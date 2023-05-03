#include <stdio.h>
#include <ctype.h>

/**
 * is_number - checks if a string is a number
 * @str: string to check
 *
 * Return: 1 if string is a number, 0 otherwise
 */
int is_number(char *str)
{
    for (int i = 0; str[i] != '\0'; i++)
    {
        if (!isdigit(str[i]))
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
	int passkey[3] = {0, 4, 2};
	int size = sizeof(passkey) / sizeof(passkey[0]);
    int guess[size];
	int guess_index, passky_index, attempt, correct_digits, correct_placement;
	const int MAX_ATTEMPTS = (size + 2);

	printf("Welcome to the numeric lock cracking game!\n");
	printf("\nCrack the Numlock!\n\
		A numeric lock has a 3-digit key [_][_][_]. The following hints are given:\n\
		-  [6][8][2] - One number is correct and well placed.\n\
		-  [6][1][4] - One number is correct but wrongly placed.\n\
		-  [2][0][6] - Two numbers are correct but wrongly placed.\n\
		-  [7][3][8] - Nothing is correct.\n\
		-  [7][8][0] - One number is wrongly placed.\n");
	printf("\nYou have %d attempts to guess the passkey.\n", MAX_ATTEMPTS);

	for (attempt = 1; attempt <= MAX_ATTEMPTS; attempt++)
	{
		printf("\nEnter your guess (%d digits between 0 and 9, separated by spaces): ", size);
		scanf("%d %d %d", &guess[0], &guess[1], &guess[2]);

		/* Check the guess against the passkey */
		correct_digits = 0;
		correct_placement = 0;
		for (guess_index = 0; guess_index < size; guess_index++)
		{
			for (passky_index = 0; passky_index < size; passky_index++)
			{
				if (guess[guess_index] == passkey[passky_index])
				{
					correct_digits++;
					if (guess_index == passky_index)
						correct_placement++;
				}
			}
		}

		/* Print hints for the guess */
		printf("\nHints:\n - [%d][%d][%d]\n", guess[0], guess[1], guess[2]);

		if (correct_placement == size)
		{
			printf("\nCongratulations! You have guessed the correct passkey! The passkey was [%d][%d][%d].\n", passkey[0], passkey[1], passkey[2]);
			break;
		} else if (attempt >= MAX_ATTEMPTS)
		{
			printf("\nSorry, you have run out of attempts. Try again!\n");
			break;
		} else {
			if (correct_placement > 0)
				printf(" -> %d number(s) correct and well placed.\n", correct_placement);
			if (correct_digits > correct_placement)
				printf(" -> %d number(s) correct but wrongly placed.\n", correct_digits - correct_placement);
			if (correct_digits == 0)
				printf(" -> Nothing is correct.\n");
		}
		printf("\nYou have %d attempt(s) remaining.\n", MAX_ATTEMPTS - attempt);
	}
	printf("Thank you for playing the numeric lock cracking game!.\n");
	return 0;
}
