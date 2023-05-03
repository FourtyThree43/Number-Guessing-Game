password = [0, 4, 2]
MAX_ATTEMPTS = 3

print("Welcome to the numeric lock cracking game!\n")
print("Crack the password!")
print("A numeric lock has a 3-digit key [_][_][_]. The following hints are given:")
print("- [6][8][2] - One number is correct and well placed.")
print("- [6][1][4] - One number is correct but wrongly placed.")
print("- [2][0][6] - Two numbers are correct but wrongly placed.")
print("- [7][3][8] - Nothing is correct.")
print("- [7][8][0] - One number is wrongly placed.")
print("\nYou have 5 attempts to guess the password.")

# Generate a random 3-digit password
# password = [random.randint(0, 9) for i in range(3)]

for attempt in range(1, MAX_ATTEMPTS + 1):
    guess = list(map(int, input("\nEnter your guess (3 digits between 0 and 9, separated by spaces): ").split()))

    # Check the guess against the password
    correct_digits = 0
    correct_placement = 0
    for guess_index in range(3):
        for passwd_index in range(3):
            if guess[guess_index] == password[passwd_index]:
                correct_digits += 1
                if guess_index == passwd_index:
                    correct_placement += 1

    # Print hints for the guess
    print("\nHints:\n - [{:d}][{:d}][{:d}] :".format(guess[0], guess[1], guess[2]))
    if correct_placement == 3:
        print("Congratulations! You have guessed the correct password!")
        break
    else:
        if correct_placement > 0:
            print(f" -> {correct_placement} number(s) correct and well placed.")
        if correct_digits > correct_placement:
            print(f" -> {correct_digits - correct_placement} number(s) correct but wrongly placed.")
        if correct_digits == 0:
            print(" -> Nothing is correct.")
    print(f"You have {MAX_ATTEMPTS - attempt} attempt(s) remaining.")

    if attempt == MAX_ATTEMPTS:
        print("\nSorry, you have failed to crack the password. Try again!")
# print(f"\nThe password was -> [{password[0]}][{password[1]}][{password[2]}].")
print("Thank you for playing the numeric lock cracking game!")
