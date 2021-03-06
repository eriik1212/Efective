#include "ModuleSceneWin.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"

ModuleSceneWin::ModuleSceneWin(bool enabled) : Module(enabled)
{
	
}

ModuleSceneWin::~ModuleSceneWin() {}

// Load assets
bool ModuleSceneWin::Start()
{
	countDown = 0;

	introBackground = App->textures->Load("Assets/UI & HUD/to_be_continued.png");
	App->audio->PlayMusic("Assets/Audio/06_shredder_final.ogg", 1.0f);
	return true;
}

update_status ModuleSceneWin::Update()
{
	countDown++;

	if (countDown > 450)
	{
		this->Disable();
		CleanUp();
		App->members->Enable();
	}

	else if (App->input->keys[SDL_SCANCODE_R] == KEY_STATE::KEY_DOWN)
	{
		this->Disable();
		CleanUp();
		App->members->Enable();
	}

	if (App->input->keys[SDL_SCANCODE_ESCAPE] == KEY_STATE::KEY_DOWN)
	{
		return update_status::UPDATE_STOP;
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleSceneWin::PostUpdate()
{
	App->render->Blit(introBackground, 0, 0, NULL, NULL, true);
	return update_status::UPDATE_CONTINUE;
}

bool ModuleSceneWin::CleanUp()
{
	bool ret;
	return true;
}
