#ifndef __MODULE_SCENELOSE_H__
#define __MODULE_SCENELOSE_H__

#include "Module.h"
#include "Animation.h"
#include "ModuleInput.h"
#include "ModuleScene.h"
#include "ModuleMembers.h"
#include "ModulePlayer.h"
#include "ModuleEnemies.h"
#include "ModuleHUD.h"

struct SDL_Texture;

class ModuleSceneLose : public Module
{
public:
	//Constructor
	ModuleSceneLose(bool enabled);

	//Destructor
	~ModuleSceneLose();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	update_status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	update_status PostUpdate() override;

	// CleanUp the scene
	bool CleanUp();

	int countDown = 0;

public:

	SDL_Texture* gameOverTexture;
};

#endif //__MODULE_SCENELOSE_H__