#include "numkey.h"

/**
 * generate_numbers_hints - Generates hints from the random numbers genarated.
 * @passkey: Pointer to the passlkey array.
 * @gen_number: Pointer to the numbers array.
 * @passkey_len: Passkey array size.
 */
void generate_numbers_hints(int *passkey, int *gen_number, int passkey_len)
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
