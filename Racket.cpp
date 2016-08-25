#include <SDL/SDL.h>
#include <inttypes.h>
#include "Racket.h"
#define STEP_SIZE 5
#define RACKET_WIDTH 60
#define RACKET_HEIGHT 20

Racket::Racket()
{
	SDL_Surface * screen = SDL_GetVideoSurface();
	racket_rect.h = RACKET_HEIGHT; 	
	racket_rect.w = RACKET_WIDTH;   
	racket_rect.x = (screen->w)/2 -(racket_rect.w)/2;
	racket_rect.y = (screen->h) - racket_rect.h;
}

Racket::Racket(int pos_x, int pos_y)
{
	racket_rect.h = RACKET_HEIGHT; 	
	racket_rect.w = RACKET_WIDTH; 
	racket_rect.x = pos_x -(racket_rect.w)/2;
	racket_rect.y = pos_y - racket_rect.h;
}

void Racket::moveRight()
{
	SDL_Surface * screen = SDL_GetVideoSurface();
	if (racket_rect.x < (screen->w) - racket_rect.w) 
		racket_rect.x += STEP_SIZE;
}		

void Racket::moveLeft()
{
	if (racket_rect.x > 0)
		racket_rect.x -= STEP_SIZE;
}
		
int Racket::getX()
{
	return racket_rect.x;
}
		
int Racket::getY()
{
	return racket_rect.y;
}
			
int Racket::getWidth()
{
	return racket_rect.w;
}

		
int Racket::getHeight()
{
	return racket_rect.h;
}
		
void Racket::addX(int _x)
{
	racket_rect.x += _x;
}
		
void Racket::addY(int _y)
{
	racket_rect.y += _y;
}
		
SDL_Rect Racket::getRect()
{
	return this->racket_rect;
}

void Racket::paint()
{
	SDL_Surface * screen = SDL_GetVideoSurface(); 
	u_int32_t color = SDL_MapRGB(screen->format, 200, 0, 200);
	SDL_FillRect(screen, &racket_rect, color);	
}
