#include <math.h>
#include "Globals.h"
#include "Application.h"
#include "Intro.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModulePlayer.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "ModuleSceneSpace.h"
#include "SDL/include/SDL_render.h"
#include "SDL/include/SDL_timer.h"

Intro::Intro()
{
	screen.x = 0;
	screen.y = 0;
	screen.h = SCREEN_HEIGHT;
	screen.w = SCREEN_WIDTH;
}

Intro::~Intro()
{}

// Load assets
bool Intro::Start()
{
	if (App->player->IsEnabled() == true)
		App->player->Disable();
	App->scene_space->Disable();
	graphics = App->textures->Load("rtype/intro.png");
	
	return true;
}

// Update: draw background
update_status Intro::Update()
{
	App->render->Blit(graphics, 0, 0, &screen);

	if (App->input->keyboard[SDL_SCANCODE_SPACE] == 1) {

		App->fade->FadeToBlack(App->introd, App->scene_space, 1);
	}


	return UPDATE_CONTINUE;
}

bool Intro::CleanUp()
{
	LOG("Unloading particles");
	if (App->introd->IsEnabled() == true)
		App->introd->Disable();
	App->textures->Unload(graphics);
	return true;
}