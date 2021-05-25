#include "ModuleSceneIntro.h"

#include "SDL/include/SDL.h"
#pragma comment( lib, "SDL/libx86/SDL2.lib")
#pragma comment( lib, "SDL/libx86/SDL2main.lib")
#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleFadeToBlack.h"

ModuleSceneIntro::ModuleSceneIntro(bool enabled) : Module(enabled)
{
	backGround.x = 550;
	backGround.y = 89;
	backGround.w = 320;
	backGround.h = 385;

	frontBuildings.x = 919;
	frontBuildings.y = 89;
	frontBuildings.w = 304;
	frontBuildings.h = 515;

	buildingLights.x = 1263;
	buildingLights.y = 114;
	buildingLights.w = 304;
	buildingLights.h = 64;

	floor.x = 1604;
	floor.y = 114;
	floor.w = 304;
	floor.h = 503;

	sewer.x = 21;
	sewer.y = 459;
	sewer.w = 60;
	sewer.h = 28;

	cloud1.PushBack({ 20, 539, 207, 29 });
	cloud1.loop = true;
	cloud1.speed = 0.15f;

	cloud2.PushBack({ 119, 461, 88, 26 });
	cloud2.loop = true;
	cloud2.speed = 0.15f;

	littleLightAnim.PushBack({ 252, 579, 64, 21 });
	littleLightAnim.PushBack({ 252, 600, 64, 21 });
	littleLightAnim.loop = true;
	littleLightAnim.speed = 1.0f;

	bigLightUpAnim.PushBack({ 573, 1733, 64, 242 });
	bigLightUpAnim.PushBack({ 492, 1733, 64, 242 });
	bigLightUpAnim.PushBack({ 413, 1733, 64, 242 });
	bigLightUpAnim.PushBack({ 336, 1733, 64, 242 });
	bigLightUpAnim.PushBack({ 255, 1733, 64, 242 });
	bigLightUpAnim.PushBack({ 181, 1733, 64, 242 });
	bigLightUpAnim.PushBack({ 100, 1733, 64, 242 });
	bigLightUpAnim.PushBack({ 19, 1733, 64, 242 });
	bigLightUpAnim.loop = false;
	bigLightUpAnim.speed = 1.0f;

	bigLightAnim.PushBack({ 19, 1733, 64, 242 });
	bigLightAnim.PushBack({ 252, 600, 64, 21 });
	bigLightAnim.loop = true;
	bigLightAnim.speed = 1.0f;

	//PATH Cloud1
	pathCloud1.PushBack({ -0.3f, 0.0f }, 300, &cloud1);

	//PATH Cloud2
	pathCloud2.PushBack({ 0.3f, 0.0f }, 300, &cloud2);

}

ModuleSceneIntro::~ModuleSceneIntro() {}

// Load assets
bool ModuleSceneIntro::Start()
{
	
	counter = 0;

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	pathCloud1.ResetRelativePosition();
	spawnPosCloud1 = iPoint((int)100, (int)65);

	pathCloud2.ResetRelativePosition();
	spawnPosCloud2 = iPoint((int)10, (int)28);

	bigLightUpAnim.Reset();

	introBackground = App->textures->Load("Assets/Introduction/introduction.png");	

	App->audio->StopMusic();

	return true;
}

update_status ModuleSceneIntro::Update()
{
	SDL_GetTicks();

	littleLightAnim.Update();
	currentAnimLight = &littleLightAnim;

	counter++;
	if (counter == 80)
	{
		App->audio->PlayMusic("Assets/Audio/01_opening_demo.ogg", 0.0f);
	}

	if (counter > 150)
	{
		App->render->camera.y += 6.0f;
	}

	pathCloud1.Update();
	positionCloud1 = spawnPosCloud1 + pathCloud1.GetRelativePosition();
	currentAnimCloud1 = pathCloud1.GetCurrentAnimation();

	pathCloud2.Update();
	positionCloud2 = spawnPosCloud2 + pathCloud2.GetRelativePosition();
	currentAnimCloud2 = pathCloud2.GetCurrentAnimation();


	if (SDL_GetTicks() > 8000)
	{
		bigLightUpAnim.Update();
		currentAnimLight = &bigLightUpAnim;
	}

	if (SDL_GetTicks() > 8150)
	{
		bigLightAnim.Update();
		currentAnimLight = &bigLightAnim;
	}


	// ScanCodes
	if ((App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN))
	{
		this->Disable();
		CleanUp();
		App->scene->Enable();
	}

	else if (App->input->keys[SDL_SCANCODE_ESCAPE] == KEY_STATE::KEY_DOWN)
	{
		return update_status::UPDATE_STOP;
	}

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleSceneIntro::PostUpdate()
{
  	App->render->Blit(introBackground, 0, 0, &backGround, 2, true); //BackGround
	App->render->Blit(introBackground, 0, 400, &frontBuildings, 7, true); //Front Buildings

	//Building Lights
	App->render->Blit(introBackground, 0, 915, &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 1), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 2), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 3), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 4), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 5), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 6), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 7), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 8), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 9), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 10), &buildingLights, 7, true);
	App->render->Blit(introBackground, 0, 915 + (64 * 11), &buildingLights, 7, true);

	//Floor
	App->render->Blit(introBackground, 0, 915 + (64 * 12), &floor, 7, true);

	//LittleLight Sewer
	if (SDL_GetTicks() > 7000 && SDL_GetTicks() < 8000)
	{
		App->render->Blit(introBackground, 127, 2138, &(currentAnimLight->GetCurrentFrame()), 7, true);
	}

	if (SDL_GetTicks() > 8000)
	{
		App->render->Blit(introBackground, 127, 1916, &(currentAnimLight->GetCurrentFrame()), 7, true);
	}

	//Sewer (Alcantarilla)
	if (SDL_GetTicks() < 8000)
	{
		App->render->Blit(introBackground, 129, 2125, &sewer, 7, true);
	}


	//Camera Limit
	if (App->render->camera.y >= 835) App->render->camera.y = 835;

	if (currentAnimCloud1 != nullptr)
	App->render->Blit(introBackground, positionCloud1.x, positionCloud1.y, &(currentAnimCloud1->GetCurrentFrame()), 2, true);

	if (currentAnimCloud2 != nullptr)
		App->render->Blit(introBackground, positionCloud2.x, positionCloud2.y, &(currentAnimCloud2->GetCurrentFrame()), 2, true);



	return update_status::UPDATE_CONTINUE;
}

bool ModuleSceneIntro::CleanUp()
{
	bool ret;
	App->textures->CleanUp();
	return true;
}
