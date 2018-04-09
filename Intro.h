#ifndef __INTRO_H__
#define __INTRO_H__

#include "Module.h"
#include "Animation.h"
#include "Globals.h"
#include "SDL\include\SDL_rect.h"

struct SDL_Texture;

class Intro : public Module
{
public:
	Intro();
	~Intro();

	bool Start();
	update_status Update();
	bool CleanUp();

private:

	SDL_Texture* graphics = nullptr;
	SDL_Rect screen;

};

#endif //__INTRO_H__