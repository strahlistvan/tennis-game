#include <SDL/SDL.h>
#include <inttypes.h>
#define STEP_SIZE 4

class Racket 
{
	private: 
		SDL_Rect racket_rect;
		
	public:
		Racket()
		{
			SDL_Surface * screen = SDL_GetVideoSurface();
			racket_rect.h = 20; 	//racket height
			racket_rect.w = 60;   //racket width
			racket_rect.x = (screen->w)/2 -(racket_rect.w)/2;
			racket_rect.y = (screen->h) - racket_rect.h;
		}
		
		Racket(int pos_x, int pos_y)
		{
			racket_rect.h = 20; 	//racket height
			racket_rect.w = 60;   //racket width
			racket_rect.x = pos_x -(racket_rect.w)/2;
			racket_rect.y = pos_y - racket_rect.h;
		}
		
		void moveRight()
		{
			SDL_Surface * screen = SDL_GetVideoSurface();
			if (racket_rect.x < (screen->w) - racket_rect.w) 
				racket_rect.x += STEP_SIZE;
		}
		
		void moveLeft()
		{
			if (racket_rect.x > 0)
				racket_rect.x -= STEP_SIZE;
		}
		
		int getX()
		{
			return racket_rect.x;
		}
		
		int getY()
		{
			return racket_rect.y;
		}
		
		int getWidth()
		{
			return racket_rect.w;
		}
		
		int getHeight()
		{
			return racket_rect.h;
		}
		
		void addX(int _x)
		{
			racket_rect.x += _x;
		}
		
		void addY(int _y)
		{
			racket_rect.y += _y;
		}
		
		SDL_Rect getRect()
		{
			return this->racket_rect;
		}
		
		void paint()
		{
		   SDL_Surface * screen = SDL_GetVideoSurface(); 
		   u_int32_t color = SDL_MapRGB(screen->format, 200, 0, 200);
		   SDL_FillRect(screen, &racket_rect, color);	
		}
		
		
};
