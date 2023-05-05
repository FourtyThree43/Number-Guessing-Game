#include "numkey.h"

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
 * generate_numbers - Generate 4 random numbers in the range [0, 9]
 *                    to be used as hints.
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
