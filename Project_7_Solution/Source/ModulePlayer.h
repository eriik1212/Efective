#ifndef __MODULE_PLAYER_H__
#define __MODULE_PLAYER_H__

#include "Module.h"
#include "Animation.h"
#include "p2Point.h"
#include "Path.h"

#define MAX_LIFE_PLAYER 10

struct SDL_Texture;
struct Collider;

class ModulePlayer : public Module
{
public:
	// Constructor
	ModulePlayer(bool enabled);

	// Destructor
	~ModulePlayer();

	// Called when the module is activated
	// Loads the necessary textures for the player
	bool Start() override;

	// Called at the middle of the application loop
	// Processes new input and handles player movement
	update_status Update() override;

	// Called at the end of the application loop
	// Performs the render call of the player sprite
	update_status PostUpdate() override;

	// Collision callback, called when the player intersects with another collider
	void OnCollision(Collider* c1, Collider* c2) override;


public:
	Path path;

	// Position of the player in the map
	iPoint position;

	// The speed in which we move the player (pixels per frame)
	int speed = 2;

	int lastPosition = 0; //    1 = Left || 0 = Right
	bool blockAnim = false;

	unsigned short lifesP1[MAX_LIFE_PLAYER];

	// The player spritesheet loaded into an SDL_Texture
	SDL_Texture* texture = nullptr;

	SDL_Texture* fireTexture = nullptr;

	SDL_Texture* smokeTexture = nullptr;

	SDL_Texture* HUDTexture = nullptr;

	SDL_Texture* AttackQuoteTexture = nullptr;

	// HUD & Foreground Animations
	Animation frontFire,
		smallFire,
		smoke,
		AttackQuote;

	// The pointer to the current player animation
	// It will be switched depending on the player's movement direction
	Animation* currentAnimation = nullptr;

	// A set of Player Animations
	Animation idleAnimR,
		idleAnimL,
		leftAnim,
		rightAnim,
		upAnimR,
		upAnimL,
		downAnimR,
		downAnimL,

		InitjumpAnimR,
		jumpAnimR,
		InitjumpAnimL,
		jumpAnimL,

		hitAirAnim1R,
		hitAirAnim2R,


		hitAirAnim1L,
		hitAirAnim2L,

		hitKickAnimR,
		hitKickAnimRFinal,

		hitKickAnimL,
		hitKickAnimLFinal,

		hitThrowAnimR,
		hitThrowAnimL,
		hitUpAnimR,
		hitUpAnimL,
		hitDownAnimR,
		hitDownAnimL,
		hitPrickAnimR,
		hitPrickAnimL,
		hitOverAnimR,
		hitOverAnimL,
		hitJumpHorizontalAnimR,
		hitJumpHorizontalAnimL,
		hitJumpSwordAnimR,
		hitJumpSwordAnimL,
		hitJumpDownAnimR,
		hitJumpDownAnimL,

		hittedLowAnim1R,
		hittedLowAnim1L,
		hittedLowAnim2R,
		hittedLowAnim2L,

		hittedMediumAnimR,
		hittedMediumAnimL,

		hittedHighAnimR,
		hittedHighAnimL,

		hittedBackLowAnimR,
		hittedBackLowAnimL,

		hittedBackMediumAnimR,
		hittedBackMediumAnimL,

		hittedBackHighAnimR,
		hittedBackHighAnimL,

		hittedGrabbedAnimR,
		hittedGrabbedAnimL,

		deathAnimR,
		deathAnimL;

	bool enemyPresence = false;

	// The player's collider
	Collider* collider = nullptr;
	Collider* HIT = nullptr;
	// A flag to detect when the player has been destroyed
	bool destroyed = false;
	bool detected = false;

	// A countdown to when the player gets destroyed. After a while, the game exits
	uint destroyedCountdown = 120;

	// Sound effects indices
	uint PunchMiss = 0;
	uint PunchHit = 0;
	uint EnemyDie = 0;
	uint Scream1 = 0;
	uint lifeIncrease = 0;
	uint lifeLost = 0;
	uint getsHit = 0;

	int counter = 0;
};

#endif //!__MODULE_PLAYER_H__
