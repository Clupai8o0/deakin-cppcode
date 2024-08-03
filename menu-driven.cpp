#include <splashkit.h>

using std::to_string;

int main() {
  string input;
  int choice;
  double a, b, c = 0;

  do {
    write_line("1. Addition");
    write_line("2. Subtraction");
    write_line("3. Multiplication");
    write_line("4. Divison");
    write_line("5. Quit");
    write_line("Enter your choice: ");
    input = read_line();

    while (!is_integer(input)) {
      write_line("Invalid input.\nPlease enter a whole number: ");
      input = read_line();
    }
    choice = convert_to_integer(input);

    if (choice == 5) break;

    write("First number: ");
    a = convert_to_double(read_line());
    write("Second number: ");
    b = convert_to_double(read_line());

    switch (choice) {
      case 1:
        c = a + b;
        break;
      case 2:
        c = a - b;
        break;
      case 3:
        c = a * b;
        break;
      case 4:
        c = a / b;
        break;
      default:
        write_line("Invalid choice.");
        break;
    }

    write_line("Result: " + to_string(c) + "\n");
  } while (choice != 5);
}