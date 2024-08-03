#include <splashkit.h>
#include "funcs.cpp"

using std::to_string;

/**
 * This function is the main game loop for the guessing game.
 */
void game()
{
  int i = 1;
  int user_guess, guess = rnd(1, 100);
  bool guessed = false;

  write_line("I am thinking of a number between 1 and 100\n");
  while (!guessed && i < 8)
  {
    // guessing integer within a particular rnage
    read_integer("Guess " + to_string(i) + ": ", 1, 100);

    // if the user guess is higher
    if (user_guess > guess)
      write_line("The number is less than " + to_string(user_guess));
    else if (user_guess < guess) // if the user guess is lower
      write_line("The number is higher than " + to_string(user_guess));
    else
    { // if guessed correctly
      write_line("Congratulations! You guessed the number correctly.");
      guessed = true;
    }
    i++;
  }

  // if not guessed
  if (!guessed)
  {
    write_line("You ran out of guesses... the number was " + to_string(guess));
  }
}

int main()
{
  string choice;

  do
  {
    game();
    choice = read_string("Do you want to play again? (y/n): ");
  } while (to_lowercase(choice) != "n");
}

// clang++ guess.cpp -o guess -l SplashKit && ./guess