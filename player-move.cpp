#include <splashkit.h>

int main()
{
  const int PLAYER_RADIUS = 50;
  const int PLAYER_SPEED = 5;
  const int SCREEN_WIDTH = 1280;
  const int SCREEN_HEIGHT = 720;

  int playerx = SCREEN_WIDTH / 2;
  int playery = SCREEN_HEIGHT / 2;

  open_window("Player Move", SCREEN_WIDTH, SCREEN_HEIGHT);

  while (!quit_requested())
  {
    clear_screen(color_white());
    fill_circle(color_turquoise(), playerx, playery, PLAYER_RADIUS);
    refresh_screen(60);

    if (key_down(RIGHT_KEY) || key_down(D_KEY) && playerx + PLAYER_RADIUS < SCREEN_WIDTH)
      playerx += PLAYER_SPEED;
    if (key_down(LEFT_KEY) || key_down(A_KEY) && playerx - PLAYER_RADIUS > 0)
      playerx -= PLAYER_SPEED;
    if (key_down(UP_KEY) || key_down(W_KEY) && playery - PLAYER_RADIUS > 0)
      playery -= PLAYER_SPEED;
    if (key_down(DOWN_KEY) || key_down(S_KEY) && playery + PLAYER_RADIUS < SCREEN_HEIGHT)
      playery += PLAYER_SPEED;

    process_events();
  }
}