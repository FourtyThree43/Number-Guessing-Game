#include "numkey.h"
#include <stddef.h>

/**
 * get_user_guess - Gets player input numbers for the guess.
 * @passkey_len: Passkey array size.
 *
 * Return: Player guess number otherwise -1 if invalid input.
 */
int get_user_guess(int passkey_len)
{
	int guess_number, i;
	char guess_str[passkey_len + 1];
	size_t passkey_length = passkey_len;

	printf("\nEnter your guess (%d digits between 0 and 9): ", passkey_len);
	scanf("%4s", guess_str);
	guess_str[strcspn(guess_str, "\n")] = 0;

	if (passkey_length != strlen(guess_str))
	{
		printf("\nInvalid entry length! Please enter %d digits between 0 and 9\n", passkey_len);
		return (-1);
	}

	for (i = 0; i < passkey_len; i++)
	{
		if (!isdigit(guess_str[i]))
		{
			printf("\nInvalid entry format! Please enter only digits between 0 and 9\n");
			return (-1);
		}
	}

	guess_number = strtol(guess_str, NULL, 10);

	if (guess_number < 0 || guess_number > 9999)
	{
		printf("\nInvalid entry format! Please enter %d digits between 0 and 9\n", passkey_len);
		return (-1);
	}
	return (guess_number);
}
