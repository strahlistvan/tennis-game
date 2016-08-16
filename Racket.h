#include <SDL/SDL.h>

class Racket 
{
	private: 
		SDL_Rect racket_rect;
		
	public:
		Racket();
		Racket(int pos_x, int pos_y);
		
		void moveRight();
		void moveLeft();
		
		int getX();
		int getY();
		int getWidth();		
		int getHeight();
		void addX(int _x);	
		void addY(int _y);
		SDL_Rect getRect();
		
		void paint();
		
};
