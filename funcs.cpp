#include "utilities.h"
#include "splashkit.h"

using std::to_string;

int main() {
  string name;
  int age, value;

  // Read in a string and store it in name
  name = read_string("enter your name: ");

  // Output the name
  write_line("Hello " + name);

  // Read in an integer
  age = read_integer("what is your age: ");
  write_line("You entered " + to_string(age));

  // Read in an integer within a range
  value = read_integer("Enter a value between 1 and 10: ", 1, 10);
  write_line("You entered " + to_string(value));
}

// clang++ funcs.cpp -o funcs -l SplashKit && ./funcs