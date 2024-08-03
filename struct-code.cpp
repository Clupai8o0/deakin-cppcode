#include <splashkit.h>

/**
 * @param name The name of the person to say hello to
 * @returns A string saying hello to the provided name
 */
string hello(string name) {
  return "Hello " + name;
}

void print_hello(string name) {
  write_line(hello(name));
}

int main() {
  print_hello("Samridh");
  return 0;
}