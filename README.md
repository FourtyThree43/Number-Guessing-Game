# NumKey

NumKey is a simple number guessing game in C that generates a passkey consisting of a sequence of numbers. The objective of the game is to guess the correct sequence of numbers in the passkey.

## Table of Contents

- [Installation](#installation)
- [Usage](#usage)
- [Gameplay](#gameplay)
- [Project-Structure](#project-structure)
- [Functions](#functions)
- [Contributing](#contributing)
- [License](#license)

## Installation

To install NumKey, clone the repository to your local machine and compile the `main.c` file:

```bash
git clone https://github.com/FourtyThree43/numkey.git
cd numkey
gcc main.c -o numkey

```

## Usage

To play NumKey, run the compiled executable numkey and follow the prompts

```bash
./numkey

```

## Gameplay

The game will prompt the user to enter the length of the passkey (up to 4 digits). Then, the game will generate a random passkey that the user needs to guess within a limited number of attempts.

The user can make a guess by entering a sequence of numbers of the same length as the passkey. The game will provide feedback on how many digits of the guess match the passkey and how many are in the correct position.

## Project Structure

The project consists of the following files:

- `main.c`: the main program that runs the game loop and controls the flow of the game.
- `getGenNum.c`: a module that generates a random passkey.
- `getGenNumHints.c`: a module that generates hints based on the generated passkey.
- `getUserNum.c`: a module that prompts the user for a guess and validates the input.
- `getUserNumHints.c`: a module that generates hints based on the user's guess.
- `numkey.h`: the header file that declares the functions used in the project.
- `LICENSE`: the license file that specifies the conditions of use and distribution of the project.
- `README.md`: the readme file that provides information about the project and its usage.
- `__tests__/NumLockGame.c`: a test file that contains test cases for the functions used in the project.

## Functions

NumKey includes the following functions in `numkey.h`:

- `generate_passkey(int *passkey, int passkey_len)`: Generates a passkey consisting of a sequence of random numbers.
- `generate_numbers(int *numbers, int passkey_len)`: Generates a sequence of random numbers.
- `generate_numbers_hints(int *passkey, int *gen_number, int passkey_len)`: Generates a sequence of random numbers with hints based on the passkey.
- `get_user_guess(int passkey_len)`: Prompts the user to enter a sequence of numbers and returns the guess as an array of integers.
- `get_user_guess_hints(int *passkey, int *guess, int passkey_len)`: Prompts the user to enter a sequence of numbers with hints based on the passkey and returns the guess as an array of integers.

## Contributing

Contributions to NumKey are welcome! To contribute, please open a pull request with your changes.

## License

The project is licensed under the MIT license. See the LICENSE file for more information.
