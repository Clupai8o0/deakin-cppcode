#include <splashkit.h>

using std::to_string;

/**
 * Displays a prompt, reads the string entered, safely converts this to an integer, and returns the value. This will display error messages when there is invalid input, and will ask the user to enter again.
 * @param prompt The prompt to display to the user.
 * @returns The integer entered by the user.
 */
int read_integer(string prompt)
{
  string output;

  write(prompt);
  output = read_line();

  if (!is_integer(output))
  {
    write_line("Please enter a valid integer.");
    return read_integer(prompt); // recursive function
  }
  return convert_to_integer(output);
}

/**
 * Displays a prompt, reads the string entered, safely converts this to an integer, and returns the value. This will display error messages when there is invalid input, and will ask the user to enter again.
 * @param prompt The prompt to display to the user.
 */
void give_change(int change)
{
  int two_dollars = 0;
  int one_dollars = 0;
  int fifty_cents = 0;
  int twenty_cents = 0;
  int ten_cents = 0;
  int five_cents = 0;

  while (change > 0)
  {
    if (change >= 200)
    {
      change -= 200;
      two_dollars += 1;
    }
    else if (change >= 100)
    {
      change -= 100;
      one_dollars += 1;
    }
    else if (change >= 50)
    {
      change -= 50;
      fifty_cents += 1;
    }
    else if (change >= 20)
    {
      change -= 20;
      twenty_cents += 1;
    }
    else if (change >= 10)
    {
      change -= 10;
      ten_cents += 1;
    }
    else
    {
      change -= 5;
      five_cents += 1;
    }
  }

  write("Change: $2 x " + to_string(two_dollars) + ", ");
  write("$1 x " + to_string(one_dollars) + ", ");
  write("50c x " + to_string(fifty_cents) + ", ");
  write("20c x " + to_string(twenty_cents) + ", ");
  write("10c x " + to_string(ten_cents) + ", ");
  write("5c x " + to_string(five_cents) + "\n");
}

int main()
{
  string choice;
  int cost, paid;

  do
  {
    cost = read_integer("Cost of item (in cents): ");
    paid = read_integer("Amount paid (in cents): ");

    //* Making sure it isn't insufficient
    if (cost > paid)
      write_line("Insufficient amount paid.");
    else
      give_change(paid - cost);

    write("\nRun again? Y/n: ");
    choice = read_line();
    while (to_lowercase(choice) != "y" && to_lowercase(choice) != "n")
    {
      write("Invalid choice. Please enter Y/n: ");
      choice = read_line();
    }
  } while (to_lowercase(choice) != "n");
}

// clang++ change-calculator.cpp -o change-calculator -l SplashKit && ./change-calculator