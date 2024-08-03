#include <splashkit.h>

/**
 * Writes a number of ‘-’ characters to the Terminal. The number of characters to write is specified in the length parameter.
 * @param length The number of ‘-’ characters to write.
 */
void print_line(int length) {
  for (int i = 0; i < length; i++) {
    write("-");
  }
  write_line("");
}

/**
 * Writes the text to the Terminal a given number of times, adding a new line when with_newline is true.
 * @param text The text to write.
 * @param times The number of times to write the text.
 * @param with_newline Whether to add a new line after the text.
 */
void print_repeated(string text, int times, bool with_newline) {
  for (int i = 0; i < times; i++) {
    write(text);
  }
  if (with_newline) {
    write_line("");
  }
}

/**
 * Writes a heading to the Terminal, with a line of ‘-’ characters above and below the heading.
 * @param heading The heading to write.
 */
void print_header(string heading) {
  int length = heading.length();

  write("\n+");
  print_repeated("-", length + 2, false);
  write_line("+");

  write_line("| " + to_uppercase(heading) + " |");
  
  write("+");
  print_repeated("-", length + 2, false);
  write_line("+\n");
}

int main() {
  string input;
  int test_length;

  print_line(20);
  write_line("| Line print test  |");
  print_line(20);

  print_header("Heading");

  print_repeated("--+--+", 5, true);
  print_repeated("Hello World\n", 5, false);
  print_repeated("--+--+", 5, true);

  write("Enter a length for a test line: ");
  input = read_line();
  test_length = stoi(input);

  print_line(test_length);
}

// clang++ print-line.cpp -o print-line -l SplashKit && ./print-line