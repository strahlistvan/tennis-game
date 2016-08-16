#include <SDL/SDL.h>
#include "Ball.h"
#include <inttypes.h>
#include <iostream>

#define BALL_SIZE 12
#define BORDER 10
#define SPEED 2

Ball::Ball()
{
    vertical = -1*SPEED;
    horizontal = -1*SPEED;
    x=(SDL_GetVideoSurface()->w)/2;
    y=SDL_GetVideoSurface()->h - 2*BORDER;
    ball_rect.h = BALL_SIZE;
    ball_rect.w = BALL_SIZE;
    ball_rect.x = x;
    ball_rect.y = y;
    SDL_FillRect(SDL_GetVideoSurface(), &ball_rect, SDL_MapRGB(SDL_GetVideoSurface()->format,255,255,255));
    fly = false;
    fallen = false;
}

void Ball::moving()
{
    if (!fly || fallen) 
		return;
    ball_rect.x = x;
    ball_rect.y = y;
    SDL_Surface * screen = SDL_GetVideoSurface();
    SDL_FillRect(screen, &ball_rect, SDL_MapRGB(SDL_GetVideoSurface()->format,255,255,255));
    x+=horizontal;
    y+=vertical;
    
    if (y <  BORDER || x < BORDER  || x > screen->w-ball_rect.w-BORDER 
		|| y > screen->h - ball_rect.h-BORDER)
    {
		std::cout<<"Ball fall down!"<<std::endl;
		fallen = true;
		return;
	}
    
    //Utkozesek vizsgalata
    if (y <= BORDER) 
		vertical*=-1; //teteje
    if (x > screen->w - ball_rect.w-BORDER) 
		horizontal*=-1; //jobb oldal
    if (x <= BORDER) 
		horizontal*=-1; //bal oldal
    if (y > screen->h - ball_rect.h-BORDER) 
		vertical*=-1; //alja
}

void Ball::bounce_up()
{
	ball_rect.y -= 2*SPEED;
	y-=2*SPEED;
	vertical*=-1;
}

void Ball::bounce_down()
{
	ball_rect.y += 2*SPEED;
	y+=2*SPEED;
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
