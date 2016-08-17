#include <SDL/SDL.h>

class Ball 
{
  private:
    double horizontal, vertical; //speed vector (velocity)
    SDL_Rect ball_rect;   //current position and size of ball
    bool fly;
    bool fallen;
  public:
    Ball();
    void moving();
    void start();
    bool is_collide(SDL_Rect object);
    void bounce_up();
    void bounce_down();
    bool is_fallen();
    void speed_up(double);
    int getX();
    int getY();
    int getWidth();
    int getHeight();
};
