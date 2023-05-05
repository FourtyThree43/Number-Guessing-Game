#ifndef NUMKEY_H
#define NUMKEY_H

/* INCLUDES */
#include <stdio.h>
#include <stdlib.h>         /* srand(), rand() */
#include <ctype.h>          /* isdigit() */
#include <string.h>         /* strlen(), strspn() */
#include <time.h>           /* seed: time() */

/* FUNCTIONS */
void generate_passkey(int *passkey, int passkey_len);
void generate_numbers(int *numbers, int passkey_len);
void generate_numbers_hints(int *passkey, int *gen_number, int passkey_len);
int get_user_guess(int passkey_len);
int get_user_guess_hints(int *passkey, int *guess, int passkey_len);

#endif /* NUMKEY_H */