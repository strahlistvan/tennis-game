#include <SDL/SDL.h>
#include "Ball.h"
#include <inttypes.h>
#include <iostream>
#include <cmath>

#define BALL_SIZE 12
#define BORDER 10
#define SPEED 2.0

Ball::Ball()
{
	SDL_Surface * screen = SDL_GetVideoSurface();
    vertical = -1*SPEED;
    horizontal = -1*SPEED;
    ball_rect.h = BALL_SIZE;
    ball_rect.w = BALL_SIZE;
    ball_rect.x = (screen->w)/2;
    ball_rect.y = screen->h - 2*BORDER;
    SDL_FillRect(screen, &ball_rect, SDL_MapRGB(screen->format,255,255,255));
    fly = false;
    fallen = false;
}

void Ball::moving()
{
    if (!fly || fallen) 
		return;
  //  ball_rect.x = x;
 //   ball_rect.y = y;
    SDL_Surface * screen = SDL_GetVideoSurface();
    SDL_FillRect(screen, &ball_rect, SDL_MapRGB(SDL_GetVideoSurface()->format,255,255,255));
    ball_rect.x+=horizontal;
    ball_rect.y+=vertical;
    
    if (ball_rect.y <  BORDER || 
		ball_rect.y > screen->h - ball_rect.h-BORDER)
    {
		std::cout<<"Ball fall down!"<<std::endl;
		fallen = true;
		return;
	}
    
    //Check collisions
    if (ball_rect.x > screen->w - ball_rect.w-BORDER) 
    {
		horizontal*=-1; //right side
		ball_rect.x -= 3*abs(horizontal);
		//x -= 3*abs(horizontal);
	}
    if (ball_rect.x <= BORDER) 
    {
		horizontal*=-1; //left side
		ball_rect.x += 3*abs(horizontal);
		//x += 3*abs(horizontal);
	}
}

void Ball::bounce_up()
{
	ball_rect.y -= 2*abs(vertical);
	//y-=2*abs(vertical);
	vertical*=-1;
}

void Ball::bounce_down()
{
	ball_rect.y += 5*abs(vertical);
//	y+=5*abs(vertical);
	vertical*=-1;
	
}

void Ball::start()
{
    fly=true;
}

bool Ball::is_fallen()
{
	return fallen;
}

bool Ball::is_collide(SDL_Rect object)
{
	if (!fly)
		return false;
	
	//check if the ball is colliding with the given object
	if (ball_rect.x < object.x + object.w &&
		ball_rect.x + ball_rect.w > object.x &&
		ball_rect.y < object.y + object.h &&
		ball_rect.y + ball_rect.h > object.y)
		{
			//std::cout<<"is collide"<<std::endl;
			return true;
		}
	return false;
}

void Ball::speed_up(double plus_speed)
{
	if (vertical > 0)
		vertical+=plus_speed;
	else 
		vertical-=plus_speed;
	if (horizontal > 0)
		horizontal+=plus_speed;
	else
		horizontal-=plus_speed;
}

 int Ball::getX()
 {
	 return ball_rect.x;
 }
 
 int Ball::getY()
 {
	 return ball_rect.y;
 }
 
 int Ball::getWidth()
 {
	 return ball_rect.w;
 }
 
 int Ball::getHeight()
 {
	 return ball_rect.h;
 }
