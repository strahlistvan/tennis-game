#include <iostream>
#include <cstdlib>
#include <ctime>
#include <SDL/SDL.h>
#include <SDL/SDL_ttf.h>
#include "Ball.h"
#include "Racket.h"
#define BORDER 10

using namespace std;

void make_menu(string, string, string);

int main (int argc, char ** argv)
{
    unsigned char * pressed_keys = SDL_GetKeyState(0);
    // initialize SDL video
    if (SDL_Init(SDL_INIT_VIDEO) < 0)
    {
		cerr<<"Unable to init SDL:"<<SDL_GetError()<<endl;
        return 1;
    }

	if (TTF_Init() != 0)
	{
		cerr << "TTF_Init() Failed: " << TTF_GetError() << endl;
		return 1;
   }

    // create a new window
    SDL_Surface * screen = SDL_SetVideoMode(640, 480, 16, SDL_HWSURFACE | SDL_DOUBLEBUF);
    SDL_WM_SetCaption("Tennis Game", "Tennis Game");

    //Start menu
	make_menu("Tennis Game", "PLAYER 1: Use arrow keys to move rackets. PLAYER 2: Use 'a' and 's' keys to move rackets.", "Press any key to continue...");
    
    Ball ball;
	Racket racket1;
	Racket racket2(50, 50);

    // program main loop
    time_t start_time = time(NULL);
    bool done = false;
    int counter = 0;
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
        
		racket1.paint();
		racket2.paint();
		 
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
        }
        //if we press 'a' key
        if (pressed_keys[SDLK_a])
        {
			racket2.moveLeft();
		}
        // If we press right key
        if (pressed_keys[SDLK_RIGHT])
        { 
			racket1.moveRight();
		}
		//if we press 'd' key
		if (pressed_keys[SDLK_d])
		{
			racket2.moveRight();
		}
		
        SDL_Flip(screen); //refresh screen
        SDL_Delay(10);   //some delay
        
        //speed up ball:
		++counter;
		if (counter%100 == 0)
		{
			ball.speed_up(0.3);
			counter = 0;
		}
		
    } // end main loop
    
    time_t elapsed = difftime(time(0), start_time);
    string winner = "Congratulations Player ";
    winner += (ball.getY() <= BORDER)? " 1 ": " 2 ";
	winner += "You are win. Elapsed time: ";
    make_menu("THE END", winner, "Press any key to exit program...");
    
    cout<<"The end ("<<ball.getX()<<","<<ball.getY()<<")"<<endl;
  
    
    SDL_FreeSurface(screen);
    SDL_Quit();
    return 0;
}

void make_menu(string text1, string text2, string text3)
{
	SDL_Surface * screen = SDL_GetVideoSurface();
	if (!screen)
	{
		cerr<<"Error! "<<SDL_GetError()<<endl;
		return;
	}
	SDL_FillRect(screen, 0, SDL_MapRGB(screen->format, 0, 0, 0));
	
	// To write text to surface (needs SDL_TTF)
	TTF_Font * pixel_font_big = TTF_OpenFont("alterebro-pixel-font.ttf", 72);
	TTF_Font * pixel_font_normal = TTF_OpenFont("alterebro-pixel-font.ttf", 24);
	SDL_Color text_color = {255, 255, 255};
	SDL_Surface * text; //surface for text
	SDL_Rect offset;  //position of the text
			
	SDL_Event start_event;
	bool started = false;
	while (!started)
	{
		while (SDL_PollEvent(&start_event))
		{
			if (start_event.type == SDL_KEYDOWN)
			{
				started = true;
			}
		}
		
		text = TTF_RenderText_Solid(pixel_font_big, text1.c_str(),
   text_color);
		offset.x = screen->w/3;
		offset.y = screen->h/3;
		SDL_BlitSurface(text, NULL, screen, &offset);
		
		offset.x = BORDER;
		offset.y = screen->h/3+100;
		
		while (text2.size() < screen->w / 10)
		{
			text2 = " "+text2+" ";
		}
		
		text = TTF_RenderText_Solid(pixel_font_normal, text2.c_str(), text_color);
		SDL_BlitSurface(text, NULL, screen, &offset);
			
		offset.x = screen->w/3;
		offset.y = screen->h/3+150;
		text = TTF_RenderText_Solid(pixel_font_normal, text3.c_str(), text_color);
		SDL_BlitSurface(text, NULL, screen, &offset);
		
		SDL_Flip(screen);
	}
}
