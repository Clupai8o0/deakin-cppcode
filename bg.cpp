#include "splashkit.h"

int main()
{
  write_line("Testing method calls");
  
  int delay_seconds;
  string user_input;

  write("How many seconds do you want it to show for? Enter seconds: ");

  user_input = read_line();

  delay_seconds = stoi(user_input);

  open_window("Test Window", 1280, 720);

  clear_screen(random_color());

  refresh_screen();

  delay(delay_seconds * 1000);
}