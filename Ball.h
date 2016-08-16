#include <SDL/SDL.h>

class Ball 
{
  private:
    int x,y;
    int horizontal, vertical; //speed vector
    SDL_Rect ball_rect;
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
};
