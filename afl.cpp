#include "splashkit.h"

using std::to_string;

string team_name1 = "", team_name2 = "";
int team_goals1 = 0, team_goals2 = 0;
int team_behinds1 = 0, team_behinds2 = 0;
int team_score1 = 0, team_score2 = 0;

/**
 * Displays a prompt, reads the string entered at the terminal, and returns this string to the caller. This can be used to read values from the user.
 * @param prompt The prompt to display to the user.
 * @returns The string entered by the user.
 */
string read_string(string prompt)
{
  write(prompt);
  return read_line();
}

/**
 * Displays a prompt, reads the string entered, safely converts this to an integer, and returns the value. This will display error messages when there is invalid input, and will ask the user to enter again.
 * @param prompt The prompt to display to the user.
 * @returns The integer entered by the user.
 */
int read_integer(string prompt)
{
  string output = read_string(prompt);
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
 * @param min The minimum value that the user can enter.
 * @param max The maximum value that the user can enter.
 * @returns The integer entered by the user.
 */
int read_integer(string prompt, int min, int max)
{
  int value;
  value = read_integer(prompt);

  if (value < min || value > max)
  {
    write_line("Please enter a value between " + to_string(min) + " and " + to_string(max));
    return read_integer(prompt, min, max);
  }
  return value;
}

/**
 * Gets the details of the two teams.
 */
void get_team_details()
{
  //* Team 1
  write_line("Enter team 1 details: ");
  team_name1 = read_string("Name: ");
  team_goals1 = read_integer("Goals: ", 0, 100);
  team_behinds1 = read_integer("Behinds: ", 0, 100);

  //* Team 2
  write_line("\nEnter team 2 details: ");
  team_name2 = read_string("Name: ");
  team_goals2 = read_integer("Goals: ", 0, 100);
  team_behinds2 = read_integer("Behinds: ", 0, 100);
}

void calculate_scores()
{
  write_line("\nCalculating details...");
  team_score1 = team_goals1 * 6 + team_behinds1;
  team_score2 = team_goals2 * 6 + team_behinds2;
}

/**
 * Prints the details of the two teams.
 */
void print_details()
{
  if (team_score1 > team_score2)
    write_line("The " + team_name1 + " are winning");
  else if (team_score2 > team_score1)
    write_line("The " + team_name2 + " are winning");
  else
    write_line("It is currently a draw");
  write_line();

  write(team_name1 + ": ");
  write(to_string(team_goals1) + ", ");
  write(to_string(team_behinds1) + ", ");
  write_line(to_string(team_score1));

  write(team_name2 + ": ");
  write(to_string(team_goals2) + ", ");
  write(to_string(team_behinds2) + ", ");
  write_line(to_string(team_score2));
}

/**
 * Asks the user if they want to quit the application.
 * @returns True if the user wants to quit, false otherwise.
 */
bool quit_app()
{
  string choice;
  choice = read_string("Are you sure you want to quit? (y/n): ");

  if (to_lowercase(choice) == "y") {
    write_line("\nGoodbye!");
    return true;
  }
  else if (to_lowercase(choice) == "n")
    return false;
  else {
    write_line("Please enter 'y' or 'n'.");
    return quit_app();
  }
}

int main()
{
  int choice;
  bool quit = false;

  write_line("Welcome to the AFL score calculator!\n");
  get_team_details();
  calculate_scores();
  print_details();

  do
  {
    write_line("\nMenu:");
    write_line("1: Update " + team_name1 + " goals");
    write_line("2: Update " + team_name1 + " behinds");
    write_line("3: Update " + team_name2 + " goals");
    write_line("4: Update " + team_name2 + " behinds");
    write_line("5: Print Details");
    write_line("6: Quit");

    choice = read_integer("Option: ", 1, 6);

    switch (choice)
    {
    case 1:
      team_goals1 = read_integer("Goals: ", 0, 100);
      break;
    case 2:
      team_behinds1 = read_integer("Behinds: ", 0, 100);
      break;
    case 3:
      team_goals2 = read_integer("Goals: ", 0, 100);
      break;
    case 4:
      team_behinds2 = read_integer("Behinds: ", 0, 100);
      break;
    case 5:
      calculate_scores();
      print_details();
      break;
    case 6:
      quit = quit_app();
      break;
    }
  } while (!quit);
}