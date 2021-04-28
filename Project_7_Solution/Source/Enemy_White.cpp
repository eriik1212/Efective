#include "Enemy_White.h"

#include "Application.h"
#include "ModuleCollisions.h"
#include "ModuleParticles.h"

Enemy_White::Enemy_White(int x, int y) : Enemy(x, y)
{

	//Walking right and down right anim
	rightAnimW.PushBack({ 0,0,98,88});
	rightAnimW.PushBack({ 98,0,98,88 });
	rightAnimW.PushBack({ 196,0,98,88 });
	rightAnimW.PushBack({ 294,0,98,88 });
	rightAnimW.PushBack({ 392,0,98,88 });
	rightAnimW.PushBack({ 490,0,98,88 });
	rightAnimW.PushBack({ 588,0,98,88 });
	rightAnimW.PushBack({ 686,0,98,88 });
	rightAnimW.loop = true;
	rightAnimW.speed = 0.15f;

	//Walking left and down left anim
	leftAnimW.PushBack({ 784,1145,98,88});
	leftAnimW.PushBack({ 784-98,1145,98,88 });
	leftAnimW.PushBack({ 784-98*2,1145,98,88 });
	leftAnimW.PushBack({ 784-98*3,1145,98,88 });
	leftAnimW.PushBack({ 784-98*4,1145,98,88 });
	leftAnimW.PushBack({ 784-98*5,1145,98,88 });
	leftAnimW.PushBack({ 784-98*6,1145,98,88 });
	leftAnimW.PushBack({ 784-98*7,1145,98,88 });
	leftAnimW.loop = true;
	leftAnimW.speed = 0.15f;

	//Walking up left anim 
	upAnimLW.PushBack({ 784, 1233, 98, 88 });
	upAnimLW.PushBack({ 784 - 98,1233,98,88 });
	upAnimLW.PushBack({ 784 - 98 * 2,1233,98,88 });
	upAnimLW.PushBack({ 784 - 98 * 3,1233,98,88 });
	upAnimLW.PushBack({ 784 - 98 * 4,1233,98,88 });
	upAnimLW.PushBack({ 784 - 98 * 5,1233,98,88 });
	upAnimLW.PushBack({ 784 - 98 * 6,1233,98,88 });
	upAnimLW.PushBack({ 784 - 98 * 7,1233,98,88 });
	upAnimLW.loop = true;
	upAnimLW.speed = 0.15f;

	//Walking up right anim 
	upAnimRW.PushBack({0,89,98,88});
	upAnimRW.PushBack({98,89,98,88});
	upAnimRW.PushBack({98*2,89,98,88 });
	upAnimRW.PushBack({98*3,89,98,88 });
	upAnimRW.PushBack({98*4,89,98,88 });
	upAnimRW.PushBack({98*5,89,98,88 });
	upAnimRW.PushBack({98*6,89,98,88 });
	upAnimRW.PushBack({98*7,89,98,88 });
	upAnimRW.loop = true;
	upAnimRW.speed = 0.15f;

	//left kick animation
	leftKickW.PushBack({784,1496,98,88});
	leftKickW.PushBack({ 784-98,1496,98,88 });
	leftKickW.PushBack({ 784 - 98*2,1496,98,88 });
	leftKickW.PushBack({ 784 - 98*3,1496,98,88 });
	leftKickW.loop = false;
	leftKickW.speed = 0.15f;

	//kick to right animation
	rightKickW.PushBack({ 0,353,98,88 });
	rightKickW.PushBack({ 98,353,98,88 });
	rightKickW.PushBack({ 98 * 2,353,98,88 });
	rightKickW.PushBack({ 98 * 3,353,98,88 });
	rightKickW.loop = false;
	rightKickW.speed = 0.15f;

	//left knife melee
	knifeMeleeLW.PushBack({ 784,1673,98,88});
	knifeMeleeLW.PushBack({ 784-98,1673,98,88 });
	knifeMeleeLW.PushBack({ 784 - 98*2,1673,98,88 });
	knifeMeleeLW.PushBack({ 784 - 98*3,1673,98,88 });
	knifeMeleeLW.loop = true;
	knifeMeleeLW.speed = 0.15f;

	//right knife melee
	knifeMeleeRW.PushBack({ 0,528,98,88 });
	knifeMeleeRW.PushBack({ 98,528,98,88 });
	knifeMeleeRW.PushBack({ 98 * 2,528,98,88 });
	knifeMeleeRW.PushBack({ 98 * 3,528,98,88 });
	knifeMeleeRW.loop = true;
	knifeMeleeRW.speed = 0.15f;

	//right knife throwing
	knifeThrowRW.PushBack({ 0,617,98,88});
	knifeThrowRW.PushBack({ 98,617,98,88 });
	knifeThrowRW.PushBack({ 98*2,617,98,88 });
	knifeThrowRW.PushBack({ 98 * 3,617,98,88 });
	knifeThrowRW.PushBack({ 98 * 4,617,98,88 });
	knifeThrowRW.PushBack({ 98 * 5,617,98,88 });
	knifeThrowRW.loop = true;
	knifeThrowRW.speed = 0.15f;

	//left knife throwing
	knifeThrowLW.PushBack({ 784,1760,98,88 });
	knifeThrowLW.PushBack({ 784 - 98,1760,98,88 });
	knifeThrowLW.PushBack({ 784 - 98 * 2 ,1760,98,88 });
	knifeThrowLW.PushBack({ 784 - 98 * 3,1760,98,88 });
	knifeThrowLW.PushBack({ 784 - 98 * 4,1760,98,88 });
	knifeThrowLW.PushBack({ 784 - 98 * 5,1760,98,88 });
	knifeThrowLW.loop = true;
	knifeThrowLW.speed = 0.15f;

	//die to right face forward
	dieFacefwRW.PushBack({ 0,705,98,88});
	dieFacefwRW.PushBack({ 98,705,98,88 }); 
	dieFacefwRW.PushBack({ 98 * 2,705,98,88 });
	dieFacefwRW.PushBack({ 98 * 3,705,98,88 });
	dieFacefwRW.PushBack({ 98 * 4,705,98,88 });
	dieFacefwRW.PushBack({ 98 * 5,705,98,88 });
	dieFacefwRW.loop = false;
	dieFacefwRW.speed = 0.15f;

	//die to right backwards
	dieBackwRW.PushBack({ 784,2026,98,88 });
	dieBackwRW.PushBack({ 784 - 98,2026,98,88 });
	dieBackwRW.PushBack({ 784 - 98 * 2,2026,98,88 });
	dieBackwRW.PushBack({ 784 - 98 * 3,2026,98,88 });
	dieBackwRW.PushBack({ 784 - 98 * 4,2026,98,88 });
	dieBackwRW.PushBack({ 784 - 98 * 5,2026,98,88 });
	dieBackwRW.loop = false;
	dieBackwRW.speed = 0.15f;

	//die to left face forward
	dieFacefwLW.PushBack({ 784,1850,98,88 });
	dieFacefwLW.PushBack({ 784 - 98,1850,98,88 });
	dieFacefwLW.PushBack({ 784 - 98 * 2,1850,98,88 });
	dieFacefwLW.PushBack({ 784 - 98 * 3,1850,98,88 });
	dieFacefwLW.PushBack({ 784 - 98 * 4,1850,98,88 });
	dieFacefwLW.PushBack({ 784 - 98 * 5,1850,98,88 });
	dieFacefwLW.loop = false;
	dieFacefwLW.speed = 0.15f;

	//die to left backwards 
	dieBackwLW.PushBack({ 0,880,98,88 });
	dieBackwLW.PushBack({ 98,880,98,88 });
	dieBackwLW.PushBack({ 98 * 2,880,98,88 });
	dieBackwLW.PushBack({ 98 * 3,880,98,88 });
	dieBackwLW.loop = false;
	dieBackwLW.speed = 0.15f;

	//aereal kick to left (not for this version)


	//aereal kick to right (not for this version)


	path.PushBack({ -1.0f, 0.0f }, 20, &leftAnimW);
	path.PushBack({ 0.0f, 0.0f }, 40, & knifeThrowLW);
	path.PushBack({ -1.0f, 0.0f }, 130, & leftAnimW);
	path.PushBack({ 1.0f,0.0f }, 150, &rightAnimW);
	path.PushBack({ 0.0f, 0.0f }, 30, &knifeMeleeRW);


	
	collider = App->collisions->AddCollider({ 0, 0, 38, 16 }, Collider::Type::ENEMY, (Module*)App->enemies);
	//HIT = App->collisions->AddCollider({ 200, 122, 40, 16 }, Collider::Type::ENEMY_HIT, (Module*)App->enemies);
}

void Enemy_White::Update()
{

	if (coolTime >= coolDown && currentAnim == &knifeThrowLW)
	{
		coolTime = 0;
		App->particles->AddParticle(App->particles->suriken, position.x +20, position.y + 74, Collider::Type::ENEMY_SHOT);
		
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