#include <splashkit.h>

using std::to_string;

//* Constants
const int MAX_GUESSES = 7;
const int MAX_NUMBER = 100;

/**
 * Perform Guess is responsible for coordinating the actions needed to
 * perform a single guess within a game of Guess that Number. The user’s
 * guess is read, and the value checked against the target value. A
 * message is then output telling the user if the target value is less
 * than, larger than, or equal to their guess. This function returns true
 * when the user’s guess is equal to the target, otherwise it returns false.
 * @param i the iteration
 * @param target The target value.
 * @returns True if the user’s guess is equal to the target, otherwise false.
 */
bool perform_guess(int i, int target)
{
  int guess;
  string input;

  write("Guess " + to_string(i) + ": ");
  input = read_line();
  if (!is_integer(input)) // making sure it is an integer
  {
    write_line("Please enter a valid integer.\n");
    return perform_guess(i, target);
  }
  guess = convert_to_integer(input);
  if (guess < 1 || guess > MAX_NUMBER) // making sure it is within the range
  {
    write_line("Please enter a number between 1 and " + to_string(MAX_NUMBER) + ".\n");
    return perform_guess(i, target);
  }

  if (guess > target)
    write_line("The number is less than " + to_string(guess));
  else if (guess < target)
    write_line("The number is higher than " + to_string(guess));
  else
  {
    write_line("Congratulations! You guessed the number correctly.");
    return true;
  }
  return false;
}

/**
 * Play game is responsible for coordinating the actions involved in
 * playing a single game of Guess that Number. Initially the computer will
 * generate a random target value, and output starting text. Then it will
 * repeatedly ask the user to guess the number, until either the user has
 * guessed the value or they have run out of guesses. If the user does run
 * out of guesses then the computer ends the game, and tells the user the target value.
 */
void play_game()
{
  int i = 1;
  int guess = rnd(1, MAX_NUMBER);
  bool guessed = false;

  write_line("I am thinking of a number between 1 and " + to_string(MAX_NUMBER) + "\n");
  while (!guessed && i <= MAX_GUESSES) {
    guessed = perform_guess(i, guess);
    i++;
  }
  
  if (!guessed)
    write_line("You ran out of guesses... the number was " + to_string(guess));
}

int main()
{
  string again;

  do {
    play_game();

    write("Play again? (y/n): ");
    again = read_line();
  } while (to_lowercase(again) != "n");
}

// clang++ guess.cpp -o guess -l SplashKit && ./guess