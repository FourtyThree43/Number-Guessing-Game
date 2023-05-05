#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

/**
 * generate_passkey - Generates random passkey for the game.
 * @passkey: Pointer to the passlkey array.
 * @passkey_len: Passkey array size.
 */
void generate_passkey(int *passkey, int passkey_len)
{
    int i, j;

    /* seed the random number generator */
    srand(time(NULL));

    passkey[0] = rand() % 10;  /* generate first number between 0 and 9 */

    for (i = 1; i < passkey_len; i++)
    {
        passkey[i] = rand() % 10;  /* generate remaining numbers */

        for (j = 0; j < i; j++)
        {
            if (passkey[i] == passkey[j])  /* check for duplicates */
            {
                i--;  /* if a duplicate is found, repeat this iteration of the loop */
                break;
            }
        }
    }
}

/**
 * generate_numbers - Generate 4 random numbers in the range [0, 9] to be used as hints.
 * @numbers: Pointer to the numbers array.
 * @passkey_len: Passkey array size.
 */
void generate_numbers(int *numbers, int passkey_len)
{
    int i, j;

    for (i = 0; i < passkey_len; i++)
    {
        numbers[i] = rand() % 10;

        for (j = 0; j < i; j++)
        {
            /* check for duplicates */
            if (numbers[i] == numbers[j])
            {
                i--;  /* if a duplicate is found, repeat this iteration of the loop */
                break;
            }
        }
    }
}

/**
 * generate_hints - Generates hints from the random numbers genarated.
 * @passkey: Pointer to the passlkey array.
 * @numbers: Pointer to the numbers array.
 * @passkey_len: Passkey array size.
 */
void generate_hints(int *passkey, int *gen_number, int passkey_len)
{
    int i, j, correct_digits = 0, correct_placement = 0;

    for (i = 0; i < passkey_len; i++)
    {
        for (j = 0; j < passkey_len; j++)
        {
            if (gen_number[i] == passkey[j])
            {
                correct_digits++;
                if (i == j)
                    correct_placement++;
            }
        }
    }

    printf("\t-> Hint: ");
    if (correct_digits == 0)
        printf("[%d][%d][%d][%d] - Nothing is correct.\n", gen_number[0], gen_number[1], gen_number[2], gen_number[3]);
    else if (correct_digits == 1 && correct_placement == 0)
        printf("[%d][%d][%d][%d] - One number is correct but wrongly placed.\n", gen_number[0], gen_number[1], gen_number[2], gen_number[3]);
    else if (correct_digits > 1 && correct_placement == 0)
        printf("[%d][%d][%d][%d] - Two or more numbers are correct but wrongly placed.\n", gen_number[0], gen_number[1], gen_number[2], gen_number[3]);
    else if (correct_placement == 1)
        printf("[%d][%d][%d][%d] - One number is correct and well placed.\n", gen_number[0], gen_number[1], gen_number[2], gen_number[3]);
    else
        printf("Invalid hints.\n");
}

/**
 * test_guess - Generates hints from the player guessed numbers.
 * @passkey: Pointer to the passlkey array.
 * @guess: Pointer to the guess array.
 * @passkey_len: Passkey array size.
 *
 * Return: 1 to continue the input otherwise -1 to break.
 */
int test_guess(int *passkey, int *guess, int passkey_len)
{
    int i, j, correct_digits = 0, correct_placement = 0;

    // Check the guess against the passkey
    for (i = 0; i < passkey_len; i++)
    {
        for (j = 0; j < passkey_len; j++)
        {
            if (guess[i] == passkey[j])
            {
                correct_digits++;
                if (i == j)
                    correct_placement++;
            }
        }
    }
    /* Print hints for the guess */
    printf("\nAlmost! here are some Hints:\n - [%d][%d][%d][%d]\n", guess[0], guess[1], guess[2], guess[3]);
    if (correct_placement == passkey_len)
    {
        printf("Congratulations! You  have guessed the correct passkey!\n");
        return -1;
    } else {
        if (correct_placement > 0)
            printf(" -> %d number(s) correct and well placed.\n", correct_placement);
        if (correct_digits > correct_placement)
            printf(" -> %d number(s) correct but wrongly placed.\n", correct_digits - correct_placement);
        if (correct_digits == 0)
            printf(" -> Nothing is correct.\n");
    }
    return 1;
}

/**
 * get_user_guess - Gets player input numbers for the guess.
 * @passkey_len: Passkey array size.
 *
 * Returns: Player guess number or -1 if invalid input.
 */
int get_user_guess(int passkey_len)
{
    int guess_number, i;
    char guess_str[passkey_len + 1];

    printf("\nEnter your guess (%d digits between 0 and 9): ", passkey_len);
    scanf("%4s", guess_str);
    guess_str[strcspn(guess_str, "\n")] = 0;

    if (strlen(guess_str) != passkey_len)
    {
        printf("\nInvalid entry length! Please enter %d digits between 0 and 9\n", passkey_len);
        return -1;
    }

    for (i = 0; i < passkey_len; i++)
    {
        if (!isdigit(guess_str[i]))
        {
            printf("\nInvalid entry format! Please enter only digits between 0 and 9\n");
            return -1;
        }
    }

    guess_number = strtol(guess_str, NULL, 10);

    if (guess_number < 0 || guess_number > 9999)
    {
        printf("\nInvalid entry format! Please enter %d digits between 0 and 9\n", passkey_len);
        return -1;
    }
    return guess_number;
}

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    const int passkey_len = 4;
    int passkey[passkey_len];
    int max_attempts = passkey_len + 2;
    int guess[passkey_len];
    int attempts = 0;
    int guesses, guessed_number;

	printf("Welcome to the numeric lock cracking game!\n");

    generate_passkey(passkey, passkey_len);
    printf("Passkey: [%d][%d][%d][%d]\n", passkey[0], passkey[1], passkey[2], passkey[3]);

    printf("\nCrack the Numlock!\n");
    printf("A numeric lock has a 4-digit key [_][_][_][_]. The following hints are given:\n");
    for (int i = 0; i < passkey_len + 1; i++)
    {
        int gen_number[passkey_len];
        generate_numbers(gen_number, passkey_len);
        //printf("Generated number: [%d][%d][%d]\n", gen_number[0], gen_number[1], gen_number[2]);
        generate_hints(passkey, gen_number, passkey_len);
    }

    for (attempts = 1; attempts <= max_attempts; attempts++)
    {
        guessed_number = get_user_guess(passkey_len);
        if (guessed_number == -1)
        {
            attempts--;
            continue;
        }

        /* Convert guess_number to an array of digits */
        for (int i = passkey_len - 1; i >= 0; i--)
        {
            guess[i] = guessed_number % 10;
            guessed_number /= 10;
        }

        guesses = test_guess(passkey, guess, passkey_len);
        if (guesses == -1)
            break;

    	printf("You have %d attempt(s) remaining.\n", max_attempts - attempts);
        if (attempts >= max_attempts)
		{
			printf("\nSorry, you have failed to crack the passkey. Try again!\n");
            printf("The passkey was: -> [%d][%d][%d][%d] <-\n", passkey[0], passkey[1], passkey[2], passkey[3]);
			break;
		}
	}
	printf("Thank you for playing the numeric lock cracking game!.\n");
    return 0;
}
