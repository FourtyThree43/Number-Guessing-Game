#include "numkey.h"

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
	int gen_number[passkey_len];
	int guess[passkey_len];
	int attempts = 0;
	int guesses, guessed_number;

	printf("Welcome to the numeric lock cracking game!\n");

	generate_passkey(passkey, passkey_len);

	printf("\nCrack the Passkey of the Numlock!\n");
	printf("A numeric lock has a 4-digit key [_][_][_][_]. The following hints are given:\n");
	for (int i = 0; i < passkey_len + 1; i++)
	{
		generate_numbers(gen_number, passkey_len);
		generate_numbers_hints(passkey, gen_number, passkey_len);
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

		guesses = get_user_guess_hints(passkey, guess, passkey_len);
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
	return (0);
}
