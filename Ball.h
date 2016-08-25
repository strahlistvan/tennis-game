#include <SDL/SDL.h>
#include <iostream>

class Ball 
{
  private:
    double horizontal, vertical; //speed vector (velocity)
    SDL_Rect ball_rect;   //current position and size of ball
    bool fly;
    bool fallen;
    std::string boing_effect; 
    
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
    void set_boing_effect(std::string wav_file_name);
    std::string get_boing_effect();
};
