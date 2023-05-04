#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int get_user_guess(int passkey_len)
{
    int guess_number, i;
    char guess_str[passkey_len + 1];

    printf("\nEnter your guess (%d digits between 0 and 9): ", passkey_len);
    scanf("%3s", guess_str);
    guess_str[strcspn(guess_str, "\n")] = 0;

    printf("\nLength of guess_str: %ld\n", strlen(guess_str));
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

    printf("Guess number: %d\n", guess_number);

    if (guess_number < 0 || guess_number > 9999)
    {
        printf("\nInvalid entry format! Please enter %d digits between 0 and 9\n", passkey_len);
        return -1;
    }
    return guess_number;
}

int main()
{
	int passkey[3] = {0, 4, 2};
	int passkey_len = sizeof(passkey) / sizeof(passkey[0]);
    int guess[passkey_len];
	int guessed_number = 0;
	int guess_index, passky_index, attempt, correct_digits, correct_placement;
	const int MAX_ATTEMPTS = (passkey_len + 2);

	printf("Welcome to the numeric lock cracking game!\n");
	printf("\nCrack the Numlock!\n");
    // Loop for multiple attempts
    for (attempt = 1; attempt <= MAX_ATTEMPTS; attempt++)
    {
        // Get the user's guess
        guessed_number = get_user_guess(passkey_len);
        printf("Guessed2: %d\n", guessed_number);
        if (guessed_number == -1)
        {
            attempt--;
            continue;
        }

        // Convert guess_number to an array of digits
        for (guess_index = passkey_len - 1; guess_index >= 0; guess_index--)
        {
            guess[guess_index] = guessed_number % 10;
            guessed_number /= 10;
        }
        // Check the guess against the passkey
        correct_digits = 0;
        correct_placement = 0;
        for (passky_index = 0; passky_index < passkey_len; passky_index++)
        {
            if (guess[passky_index] == passkey[passky_index])
                correct_placement++;
            if (memchr(passkey, guess[passky_index], passkey_len) != NULL)
                correct_digits++;
        }
        correct_digits -= correct_placement;

        // Print the result
        printf("\nHints:\n - [%d][%d][%d]\n", guess[0], guess[1], guess[2]);
        printf("%d Attempt Remaining\n", MAX_ATTEMPTS - attempt);
        if (correct_placement == passkey_len)
        {
            printf("Congratulations! You cracked the numlock!\n");
            break;
        } else if (attempt >= MAX_ATTEMPTS)
        {
            printf("Sorry, you didn't crack the numlock. The passkey was [%d][%d][%d].\n", passkey[0], passkey[1], passkey[2]);
        }/*else {
			if (correct_placement > 0)
				printf(" -> %d number(s) correct and well placed.\n", correct_placement);
			if (correct_digits > correct_placement)
				printf(" -> %d number(s) correct but wrongly placed.\n", correct_digits - correct_placement);
			if (correct_digits == 0)
				printf(" -> Nothing is correct.\n");
		}*/
        //printf("%d digits were correct, %d were in the correct position.\n", correct_digits, correct_placement);
    }
    return 0;
}