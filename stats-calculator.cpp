#include <splashkit.h>
using std::to_string;

int main() {
  string input, choice;
  int value, count = 1;
  double total = 0, min = 0, max = 0, avg = 0;

  write_line("Welcome to simple stats calculator:\n");

  do {
    write("Enter a value: ");
    input = read_line();
    while (!is_integer(input)) {
      write("Invalid input. Please enter a valid number: ");
      input = read_line();
    }
    value = convert_to_integer(input);

    total += value;
    if (value < min || count == 1) min = value;
    if (value > max || count == 1) max = value;
    avg = total / count;

    write_line("Count: " + to_string(count));
    write_line("Total: " + to_string(total));
    write_line("Min: " + to_string(min));
    write_line("Max: " + to_string(max));
    write_line("Average: " + to_string(avg));

    count++;

    write("\nAdd another value: [y/n]");
    choice = read_line();
    while (to_lowercase(choice) != "y" && to_lowercase(choice) != "n") {
      write("Invalid input. Please enter [y/n]: ");
      choice = read_line();
    }
  } while (to_lowercase(choice) != "n");
}