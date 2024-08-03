#ifndef UTILITIES_H
#define UTILITIES_H

#include <string>
using std::string;

/**
 * Displays a prompt, reads the string entered at the terminal, and returns this string to the caller. This can be used to read values from the user.
 * @param prompt The prompt to display to the user.
 * @returns The string entered by the user.
 */
string read_string(string prompt);

/**
 * Displays a prompt, reads the string entered, safely converts this to an integer, and returns the value. This will display error messages when there is invalid input, and will ask the user to enter again.
 * @param prompt The prompt to display to the user.
 * @returns The integer entered by the user.
 */
int read_integer(string prompt);

/**
 * Displays a prompt, reads the string entered, safely converts this to an integer, and returns the value. This will display error messages when there is invalid input, and will ask the user to enter again.
 * @param prompt The prompt to display to the user.
 * @param min The minimum value that the user can enter.
 * @param max The maximum value that the user can enter.
 * @returns The integer entered by the user.
 */
int read_integer(string prompt, int min, int max);

#endif