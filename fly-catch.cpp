#include <splashkit.h>
using std::to_string;

//* Constants
const string GAME_TIMER = "gameTimer";
const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int SPIDER_SIZE = 25;
const int SPIDER_SPEED = 20;
const int FLY_SIZE = 15;

void draw_game(int spiderX, int spiderY, int flyX, int flyY, bool flyAppeared, int points)
{
  clear_screen(color_white());
  draw_text("Points: " + to_string(points), color_black(), 0, 0);
  fill_circle(color_black(), spiderX, spiderY, SPIDER_SIZE);

  //* Show the fly
  if (flyAppeared)
    fill_circle(color_gray(), flyX, flyY, FLY_SIZE);

  refresh_screen(120);
}

int main()
{
  //* Variables
  int spiderX = SCREEN_WIDTH / 2,
      spiderY = SCREEN_HEIGHT / 2;
  int points = 0;
  int flyX = 0, flyY = 0;
  bool flyAppeared = false, flyCaught = false;
  long appearAt = 1000 + rnd(2000), escapeAt = 0;

  //* Time
  create_timer(GAME_TIMER);
  start_timer(GAME_TIMER);

  //* Opening window
  open_window("Fly Catch", SCREEN_WIDTH, SCREEN_HEIGHT);

  //* Game loop
  while (!quit_requested())
  {
    //* Moving the spider
    if ((key_down(RIGHT_KEY) || key_down(D_KEY)) && spiderX + SPIDER_SPEED + SPIDER_SIZE < SCREEN_WIDTH)
      spiderX += SPIDER_SPEED;
    if ((key_down(LEFT_KEY) || key_down(A_KEY)) && spiderX - SPIDER_SPEED > 0)
      spiderX -= SPIDER_SPEED;
    if ((key_down(UP_KEY) || key_down(W_KEY)) && spiderY - SPIDER_SPEED > 0)
      spiderY -= SPIDER_SPEED;
    if ((key_down(DOWN_KEY) || key_down(S_KEY)) && spiderY + SPIDER_SPEED + SPIDER_SIZE < SCREEN_HEIGHT)
      spiderY += SPIDER_SPEED;

    //* Fly parameters
    if (!flyAppeared && timer_ticks(GAME_TIMER) > appearAt && !flyCaught)
    {
      flyAppeared = true;
      escapeAt = appearAt + 1000 + rnd(2000, 7000);
      flyX = rnd(FLY_SIZE, SCREEN_WIDTH - FLY_SIZE);
      flyY = rnd(FLY_SIZE, SCREEN_HEIGHT - FLY_SIZE);
    }
    else if ((flyAppeared && timer_ticks(GAME_TIMER) > escapeAt) || flyCaught)
    {
      flyAppeared = false;
      flyCaught = false;
      appearAt = timer_ticks(GAME_TIMER) + 1000 + rnd(2000);
    }

    //* If the spider and the fly are intersecting
    if (flyAppeared && circles_intersect(spiderX, spiderY, SPIDER_SIZE, flyX, flyY, FLY_SIZE))
    {
      flyCaught = true;
      flyAppeared = false;
      points++;
    }

    //* Making the spider appear
    draw_game(spiderX, spiderY, flyX, flyY, flyAppeared, points);
    process_events();
  }
}