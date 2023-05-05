#include "numkey.h"

/**
 * get_user_guess_hints - Generates hints from the player guessed numbers.
 * @passkey: Pointer to the passlkey array.
 * @guess: Pointer to the guess array.
 * @passkey_len: Passkey array size.
 *
 * Return: 1 to continue the input otherwise -1 to break.
 */
int get_user_guess_hints(int *passkey, int *guess, int passkey_len)
{
	int i, j, correct_digits = 0, correct_placement = 0;

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
		return (-1);
	}
	else if (correct_placement > 0)
		printf(" -> %d number(s) correct and well placed.\n", correct_placement);
	else if (correct_digits > correct_placement)
		printf(" -> %d number(s) correct but wrongly placed.\n", correct_digits - correct_placement);
	else if (correct_digits == 0)
		printf(" -> Nothing is correct.\n");

	return (1);
}
