#include "Enemy_Purple.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"

Enemy_Purple::Enemy_Purple(int x, int y) : Enemy(x, y)
{

	// RIGHT
	rightAnimP.PushBack({ 0, 453, 86, 90 });
	rightAnimP.PushBack({ 86, 453, 86, 90 });
	rightAnimP.PushBack({ 86 * 2, 453, 86, 90 });
	rightAnimP.PushBack({ 86 * 3, 453, 86, 90 });
	rightAnimP.PushBack({ 86 * 4, 453, 86, 90 });
	rightAnimP.PushBack({ 86 * 5, 453, 86, 90 });
	rightAnimP.PushBack({ 86 * 6, 453, 86, 90 });
	rightAnimP.PushBack({ 86 * 7, 453, 86, 90 });
	rightAnimP.loop = true;
	rightAnimP.speed = 0.15f;

	//LEFT
	leftAnimP.PushBack({1032,1890,86,90});
	leftAnimP.PushBack({ 1032-86,1890,86,90 });
	leftAnimP.PushBack({ 1032 - 86 * 2,1890,86,90 });
	leftAnimP.PushBack({ 1032 - 86 * 3,1890,86,90 });
	leftAnimP.PushBack({ 1032 - 86 * 4,1890,86,90 });
	leftAnimP.PushBack({ 1032 - 86 * 5,1890,86,90 });
	leftAnimP.PushBack({ 1032 - 86 * 6,1890,86,90 });
	leftAnimP.PushBack({ 1032 - 86 * 7,1890,86,90 });
	leftAnimP.loop = true;
	leftAnimP.speed = 0.15f;

	//UP LEFT
	upAnimLP.PushBack({ 1032,1980,86,90 });
	upAnimLP.PushBack({ 1032 - 86,1980,86,90 });
	upAnimLP.PushBack({ 1032 - 86 * 2,1980,86,90 });
	upAnimLP.PushBack({ 1032 - 86 * 3,1980,86,90 });
	upAnimLP.PushBack({ 1032 - 86 * 4,1980,86,90 });
	upAnimLP.PushBack({ 1032 - 86 * 5,1980,86,90 });
	upAnimLP.PushBack({ 1032 - 86 * 6,1980,86,90 });
	upAnimLP.PushBack({ 1032 - 86 * 7,1980,86,90 });
	upAnimLP.loop = true;
	upAnimLP.speed = 0.15f;

	//UP RIGHT
	upAnimRP.PushBack({ 0, 443, 86, 90 });
	upAnimRP.PushBack({ 86, 443, 86, 90 });
	upAnimRP.PushBack({ 86 * 2, 443, 86, 90 });
	upAnimRP.PushBack({ 86 * 3, 443, 86, 90 });
	upAnimRP.PushBack({ 86 * 4, 443, 86, 90 });
	upAnimRP.PushBack({ 86 * 5, 443, 86, 90 });
	upAnimRP.PushBack({ 86 * 6, 443, 86, 90 });
	upAnimRP.PushBack({ 86 * 7, 443, 86, 90 });
	upAnimRP.loop = true;
	upAnimRP.speed = 0.15f;


	//RIGHT KICK
	kickRP.PushBack({ 0, 90, 86, 90 });
	kickRP.PushBack({ 86, 90, 86, 90 });
	kickRP.PushBack({ 86 * 2, 90, 86, 90 });
	kickRP.PushBack({ 86 * 3, 90, 86, 90 });
	kickRP.loop = true; //it can be true
	kickRP.speed = 0.15f;

	//LEFT KICK
	kickLP.PushBack({ 1032,1530,86,90 });
	kickLP.PushBack({ 1032 - 86,1530,86,90 });
	kickLP.PushBack({ 1032 - 86 * 2,1530,86,90 });
	kickLP.PushBack({ 1032 - 86 * 3,1530,86,90 });
	kickLP.loop = false; //it can be true
	kickLP.speed = 0.15f;

	//LEFT PUNCH
	punchLP.PushBack({ 1032, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86 * 2, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86 * 3, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86 * 4, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86 * 5, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86 * 6, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86 * 7, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86 * 8, 2790, 86, 90 });
	punchLP.PushBack({ 1032 - 86 * 9, 2790, 86, 90 });
	punchLP.loop = true; //it can be true
	punchLP.speed = 0.15f;

	//RIGHT PUNCH
	punchRP.PushBack({ 0, 1350, 86, 90 });
	punchRP.PushBack({ 86, 1350, 86, 90 });
	punchRP.PushBack({ 86 * 2, 1350, 86, 90 });
	punchRP.PushBack({ 86 * 3, 1350, 86, 90 });
	punchRP.PushBack({ 86 * 4, 1350, 86, 90 });
	punchRP.PushBack({ 86 * 5, 1350, 86, 90 });
	punchRP.PushBack({ 86 * 6, 1350, 86, 90 });
	punchRP.PushBack({ 86 * 7, 1350, 86, 90 });
	punchRP.PushBack({ 86 * 8, 1350, 86, 90 });
	punchRP.PushBack({ 86 * 9, 1350, 86, 90 });
	punchRP.loop = true; //it can be true
	punchRP.speed = 0.15f;

	//RIGHT JUMP
	jumpRP.PushBack({ 0, 900, 86, 90 });
	jumpRP.PushBack({ 86, 900, 86, 90 });
	jumpRP.PushBack({ 86 * 2, 900, 86, 90 });
	jumpRP.PushBack({ 86 * 3, 900, 86, 90 });
	jumpRP.PushBack({ 86 * 4, 900, 86, 90 });
	jumpRP.PushBack({ 86 * 5, 900, 86, 90 });
	jumpRP.PushBack({ 86 * 6, 900, 86, 90 });
	jumpRP.loop = false; //it can be true
	jumpRP.speed = 0.15f;

	//LEFT JUMP
	jumpLP.PushBack({ 1032,2340,86,90 });
	jumpLP.PushBack({ 1032 - 86,2340,86,90 });
	jumpLP.PushBack({ 1032 - 86 * 2,2340,86,90 });
	jumpLP.PushBack({ 1032 - 86 * 3,2340,86,90 });
	jumpLP.PushBack({ 1032 - 86 * 4,2340,86,90 });
	jumpLP.PushBack({ 1032 - 86 * 5,2340,86,90 });
	jumpLP.PushBack({ 1032 - 86 * 6,2340,86,90 });
	jumpLP.loop = true; //it can be true
	jumpLP.speed = 0.15f;

	
	path.PushBack({ -1.2f, 0.0f }, 45, &jumpLP);
	path.PushBack({ -1.2f, 0.0f }, 50, & leftAnimP);
	path.PushBack({ 0.0f, 0.0f }, 68, & punchLP);
	path.PushBack({1.2f, 0.0f}, 120, &rightAnimP);
	path.PushBack({ 0.0f, 0.0f }, 25, & kickRP);
	path.PushBack({ -1.2f, 0.0f }, 20, & leftAnimP);
	

	collider = App->collisions->AddCollider({0, 0, 38, 16}, Collider::Type::ENEMY, (Module*)App->enemies);
	HIT = App->collisions->AddCollider({ 200, 122, 40, 16 }, Collider::Type::ENEMY_SHOT, (Module*)App->enemies);
	//SEE = App->collisions->AddCollider({ 150, 122, 70, 16 }, Collider::Type::SEE, (Module*)App->enemies);
}

void Enemy_Purple::Update()
{

	App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_SHOT] = false;

	if (coolTime >= coolDown) 
	{
		App->collisions->matrix[Collider::Type::PLAYER][Collider::Type::ENEMY_SHOT] = true;
		coolTime = 0;	
		App->particles->AddParticle(App->particles->suriken, position.x + 20, position.y+74, Collider::Type::ENEMY_SHOT);
	
	}
	else 
	{
		coolTime += 0.1;

	}

	path.Update();
	position = spawnPos + path.GetRelativePosition();
	currentAnim = path.GetCurrentAnimation();
	
	// Call to the base class. It must be called at the end
	// It will update the collider depending on the position
	Enemy::Update();
}
