#include "ModuleRender.h"

#include "Application.h"

#include "ModuleWindow.h"
#include "ModuleTextures.h"
#include "ModuleInput.h"

#include "SDL/include/SDL_render.h"
#include "SDL/include/SDL_scancode.h"

ModuleRender::ModuleRender(bool enabled) : Module(enabled)
{

}

ModuleRender::~ModuleRender()
{

}

bool ModuleRender::Init()
{
	LOG("Creating Renderer context");
	bool ret = true;	
	Uint32 flags = 0;

	if (VSYNC == true)
	{
		flags |= SDL_RENDERER_PRESENTVSYNC;
	}

	renderer = SDL_CreateRenderer(App->window->window, -1, flags);

	if (renderer == nullptr)
	{
		LOG("Renderer could not be created! SDL_Error: %s\n", SDL_GetError());
		ret = false;
	}
	SDL_RenderSetLogicalSize(renderer ,SCREEN_WIDTH*3,SCREEN_HEIGHT*3);
	return ret;
}

// Called every draw update
update_status ModuleRender::PreUpdate()
{
	//Set the color used for drawing operations
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	//Clear rendering target
	SDL_RenderClear(renderer);

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::Update()
{
	//MANUAL CAMERA MOVEMENT (IF NEEDED)
	/*if (App->input->keys[SDL_SCANCODE_L] == KEY_STATE::KEY_REPEAT) {
		camera.x += cameraSpeed;
	}
	else if (App->input->keys[SDL_SCANCODE_J] == KEY_STATE::KEY_REPEAT) {
		camera.x -= cameraSpeed;
	}
	else if (App->input->keys[SDL_SCANCODE_K] == KEY_STATE::KEY_REPEAT) {
		camera.y += cameraSpeed;
	}
	else if (App->input->keys[SDL_SCANCODE_I] == KEY_STATE::KEY_REPEAT) {
		camera.y -= cameraSpeed;
	}*/

	return update_status::UPDATE_CONTINUE;
}

update_status ModuleRender::PostUpdate()
{
	//Update the screen
	SDL_RenderPresent(renderer);

	return update_status::UPDATE_CONTINUE;
}

bool ModuleRender::CleanUp()
{
	LOG("Destroying renderer");

	//Destroy the rendering context
	if (renderer != nullptr)
		SDL_DestroyRenderer(renderer);

	return true;
}

// Blit to screen
bool ModuleRender::Blit(SDL_Texture* texture, int x, int y, const SDL_Rect* section, float speed, bool useCamera)
{
	bool ret = true;

	SDL_Rect dstRect{ x * SCREEN_SIZE, y * SCREEN_SIZE, 0, 0 };

	if (useCamera)
	{
		dstRect.x -= (camera.x * speed);
		dstRect.y -= (camera.y * speed);
	}

	if (section != nullptr)
	{
		dstRect.w = section->w;
		dstRect.h = section->h;
	}
	else
	{
		//Collect the texture size into rect.w and rect.h variables
		SDL_QueryTexture(texture, nullptr, nullptr, &dstRect.w, &dstRect.h);
	}

	dstRect.w *= SCREEN_SIZE;
	dstRect.h *= SCREEN_SIZE;

	if (SDL_RenderCopy(renderer, texture, section, &dstRect) != 0)
	{
		LOG("Cannot blit to screen. SDL_RenderCopy error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}

bool ModuleRender::DrawQuad(const SDL_Rect& rect, Uint8 r, Uint8 g, Uint8 b, Uint8 a, float speed)
{
	bool ret = true;

	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	SDL_SetRenderDrawColor(renderer, r, g, b, a);

	SDL_Rect dstRect {
		(int)(-camera.x * speed) + rect.x * SCREEN_SIZE,
		(int)(-camera.y * speed) + rect.y * SCREEN_SIZE,
		rect.w * SCREEN_SIZE, rect.h * SCREEN_SIZE };

	if (SDL_RenderFillRect(renderer, &dstRect) != 0)
	{
		LOG("Cannot draw quad to screen. SDL_RenderFillRect error: %s", SDL_GetError());
		ret = false;
	}

	return ret;
}