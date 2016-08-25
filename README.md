# Tennis Game for two players

A classic ball game written in C++ with SDL graphic library.

## Controls
- First player: Right and left arrow
- Second player: 'A' and 'D' buttons

## Requirements 
- C++ compiler with SDL 1.2, SDL_TTF and SDL_Mixer library
- GNU Make (optional)

## Install on Linux
- To install SDL 1.2 `$ (sudo) apt-get install libsdl1.2-dev`
- To install SDL TTF `$ (sudo) apt-get install libsdl-ttf2.0-dev`
- Build the project with Makefile 
- Or compile manually: `$ g++ main.cpp Ball.cpp Racket.cpp -lSDL -lSDL_ttf -lSDL_mixer`

## Install on Windows
- Run the tennis-game.exe 
- Important: all the `*.dll` files, the wav files, the ttf font and `tennis-game.exe` must be in the same folder.
