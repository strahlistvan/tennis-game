#include <iostream>
#include <cstdlib>
#include <SDL/SDL.h>
#include "Ball.h"
#include "Racket.h"

int main ( int argc, char** argv )
{
    unsigned char * pressed_keys = SDL_GetKeyState(0);
    // initialize SDL video
    if ( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
		std::cerr<<"Unable to init SDL:"<<SDL_GetError()<<std::endl;
        return 1;
    }

    // create a new window
    SDL_Surface * screen = SDL_SetVideoMode(640, 480, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
    Ball ball;
	Racket racket1;
	Racket racket2(50, 50);

    // program main loop
    bool done = false;
    while (!done)
    {
        // message processing loop
        SDL_Event event;
        while (SDL_PollEvent(&event))
        {
            // check for messages
            switch (event.type)
            {
                // exit if the window is closed
				case SDL_QUIT:
				{
					done = true;
					break;
				}

				 // check for keypresses
				case SDL_KEYDOWN:
				{
					  // exit if ESCAPE is pressed
					  if (event.key.keysym.sym == SDLK_ESCAPE)
						 done = true;
					  break;
				}
			} // end switch
        } // end of message processing
         SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
        // DRAWING STARTS HERE bricks
   /*      SDL_Rect tegla;
         int k=0; //k eltolas miatt
        for (int i=0; i<screen->h/2; i+=tegla.h+5) //lefele megy
            for (int j=k; j<screen->w; j+=tegla.w+5) //balra megy
            {
				tegla.x=j; tegla.y=i;
				tegla.h=10; tegla.w=30;
				SDL_FillRect(screen,&tegla,SDL_MapRGB(screen->format,200,20,0));
				if (k)
					k+=5;
				else 
					k-=5;
             }
   */
		racket1.paint();
		racket2.paint();
		
        if (pressed_keys[SDLK_SPACE]) 
			ball.start();
		
		ball.moving();
		
		//collide with bottom racket
		if (ball.is_collide(racket1.getRect()))
			ball.bounce_up();
		//collide with top racket
		if (ball.is_collide(racket2.getRect()))
			ball.bounce_down();
			
		if (ball.is_fallen())
		{
			std::cout<<"The end"<<std::endl;
			break;
		}
        
        // If we press left key:
        if (pressed_keys[SDLK_LEFT])
        { 
			racket1.moveLeft();
			racket2.moveLeft();
			
        }
        // If we press right key
        if (pressed_keys[SDLK_RIGHT])
        { 
			racket1.moveRight();
			racket2.moveRight();
		}
        SDL_Flip(screen); //refresh screen
        SDL_Delay(15);   //some delay
    } // end main loop
    
    return 0;
}

