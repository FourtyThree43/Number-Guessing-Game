const std = @import("std");

pub fn main() !void {
    const passkey = [_]u8{0, 4, 2};
    const size: usize = passkey.len;
    var guess: [size]u8 = undefined;
    var guess_index: usize = undefined;
    var passky_index: usize = undefined;
    var attempt: usize = undefined;
    var correct_digits: usize = undefined;
    var correct_placement: usize = undefined;
    const MAX_ATTEMPTS: usize = (size + 2);

    std.debug.print("Welcome to the numeric lock cracking game!\n");
    std.debug.print("\nCrack the Numlock!\n");
    std.debug.print("    A numeric lock has a 3-digit key [_][_][_]. The following hints are given:");
    std.debug.print("    -  [6][8][2] - One number is correct and well placed.");
    std.debug.print("    -  [6][1][4] - One number is correct but wrongly placed.");
    std.debug.print("    -  [2][0][6] - Two numbers are correct but wrongly placed.");
    std.debug.print("    -  [7][3][8] - Nothing is correct.");
    std.debug.print("    -  [7][8][0] - One number is wrongly placed.\n");
    std.debug.print("\nYou have {} attempts to guess the passkey.\n", .{MAX_ATTEMPTS});

    for (attempt) |guess| {
        std.debug.print("\nEnter your guess ({:d} digits between 0 and 9, separated by spaces): ", .{size});
        _, guess[0..size] = try std.fmt.scan(u8, size, "_ _ _");

        // Check the guess against the passkey
        correct_digits = 0;
        correct_placement = 0;
        for (guess_index = 0; guess_index < size; guess_index += 1) {
            for (passky_index = 0; passky_index < size; passky_index += 1) {
                if (guess[guess_index] == passkey[passky_index]) {
                    correct_digits += 1;
                    if (guess_index == passky_index)
                        correct_placement += 1;
                }
            }
        }

        std.debug.print("Correct digits: {}\n", .{correct_digits});
        std.debug.print("Correct placement: {}\n", .{correct_placement});

        // Print hints for the guess
        std.debug.print("\nHints:\n - [{}][{}][{}]\n", .{guess[0], guess[1], guess[2]});

        if (correct_placement == size) {
            std.debug.print("\nCongratulations! You have guessed the correct passkey! The passkey was [{}][{}][{}].\n", .{passkey[0], passkey[1], passkey[2]});
            break;
        } else if (attempt >= MAX_ATTEMPTS) {
            std.debug.print("\nSorry, you have run out of attempts. Try again!\n");
            break;
        } else {
            if (correct_placement > 0) {
                std.debug.print(" -> {} number(s) correct and well placed.\n", .{correct_placement});
            }
            if (correct_digits > correct_placement) {
                std.debug.print(" -> {} number(s) correct but wrongly placed.\n", .{correct_digits - correct_placement});
            }
            if (correct_digits == 0) {
                std.debug.print(" -> Nothing is correct.\n", .{});
            }
        }
        std.debug.print("\nYou have {} attempt(s) remaining.\n", .{MAX_ATTEMPTS - attempt});
    }

    std.debug.print("Thank you for playing the numeric lock cracking game!.\n");
}


fn parse_input(input_str: []const u8) ![]u8 {
    var input_arr = [_]u8{0, 0, 0};
    var input_items = std.string.split(input_str, " ");

    if (input_items.len != 3) {
        return error.InvalidInput;
    }
    for (i, input_item: std.mem.span(u8, input_items)) |input_item| {
        var digit: u8 = 0;
        if (input_item[0] < '0' or input_item[0] > '9') {
            return error.InvalidInput;
        }
        digit += (input_item[0] - '0') * 100;
        if (input_item[1] < '0' or input_item[1] > '9') {
            return error.InvalidInput;
        }
        digit += (input_item[1] - '0') * 10;
        if (input_item[2] < '0' or input_item[2] > '9') {
            return error.InvalidInput;
        }
        digit += input_item[2] - '0';
        input_arr[i] = digit;
    }
    return input_arr;
}
