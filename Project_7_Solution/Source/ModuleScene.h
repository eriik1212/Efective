#ifndef __MODULE_SCENE_H__
#define __MODULE_SCENE_H__

#include "Module.h"
#include "Animation.h"
#include "ModuleInput.h"

struct SDL_Texture;

class ModuleScene : public Module
{
public:
	//Constructor
	ModuleScene(bool enabled);

	//Destructor
	~ModuleScene();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	update_status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	update_status PostUpdate() override;

	bool CleanUp();

public:
	
	SDL_Rect background;

	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* stageTexture = nullptr;

	Animation fireDoor, 
		doorBreak,
		doorBreak2,
		doorBreak3,
		
		fireElev,
		openElev,
		openElev2;
	//Initialazing scene audio index
	uint DoorBrake = 0;
	uint ElevatorDoor = 0;
public:
	// Game Over
	SDL_Texture* gameOverTexture = nullptr;
	bool gameOver = false;
	int gOverCounter = 0;
};


#endif //__MODULE_SCENE_H__