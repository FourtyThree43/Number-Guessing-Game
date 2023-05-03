#include <stdio.h>

int main()
{
	int passkey[4] = {4, 3, 9, 1};
	int size = sizeof(passkey) / sizeof(passkey[0]);
    int guess[size];
	int guess_index, passky_index, attempt, correct_digits, correct_placement;
	const int MAX_ATTEMPTS = (size + 2);

	printf("Welcome to the numeric lock cracking game!\n");
	printf("\nCrack the Numlock!\n\
		A numeric lock has a 4-digit key [_][_][_][_]. The following hints are given:\n\
		-  [9][2][8][5] - One number is correct but wrongly placed.\n\
		-  [1][9][3][7] - Three numbers are correct but wrongly placed.\n\
		-  [5][2][0][1] - One number is correct and well placed.\n\
		-  [6][5][0][7] - Nothing is correct.\n\
		-  [3][8][2][4] - Two numbers are correct but wrongly placed.\n");
	printf("\nYou have %d attempts to guess the passkey.\n", MAX_ATTEMPTS);

	for (attempt = 1; attempt <= MAX_ATTEMPTS; attempt++)
	{
		printf("\nEnter your guess (%d digits between 0 and 9, separated by spaces): ", size);
		scanf("%d %d %d %d", &guess[0], &guess[1], &guess[2], &guess[3]);

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
		printf("\nHints:\n - [%d][%d][%d][%d]\n", guess[0], guess[1], guess[2], guess[3]);
		if (correct_placement == size)
		{
			printf("Congratulations! You  have guessed the correct passkey!\n");
			break;
		}else if (attempt >= MAX_ATTEMPTS)
		{
			printf("\nSorry, you have failed to crack the passkey. Try again!\n");
			break;
		} else {
			if (correct_placement > 0)
				printf(" -> %d number(s) correct and well placed.\n", correct_placement);
			if (correct_digits > correct_placement)
				printf(" -> %d number(s) correct but wrongly placed.\n", correct_digits - correct_placement);
			if (correct_digits == 0)
				printf(" -> Nothing is correct.\n");
		}
		printf("You have %d attempt(s) remaining.\n", MAX_ATTEMPTS - attempt);
	}
	printf("Thank you for playing the numeric lock cracking game!.\n");
	return 0;
}
