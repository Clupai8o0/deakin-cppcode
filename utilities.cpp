#include "utilities.h"
#include "splashkit.h"

using std::to_string;

string read_string(string prompt)
{
  write(prompt);
  return read_line();
}

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