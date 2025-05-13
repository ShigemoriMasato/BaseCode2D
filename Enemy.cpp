#include "Enemy.h"

Enemy::Enemy(Camera* camera) : Object()
{
	Initialize(camera);
}

Enemy::~Enemy()
{
}

void Enemy::Initialize(Camera* camera)
{
	
	velocity_ = { 2.0f,2.0f };

	scale_ = { 1.0f,1.0f };

	
	for (int i = 0; i < MaxEnemyNum_; i++)
	{
		isActive_[i] = true;

		isAlive_[i] = true;

		pos_[i] = { 640.0f,200.0f + i* 30};
	}

	

	enemyKinds_ = EnemyKinds::Mob;

	camera_ = camera;
}

void Enemy::Update()
{
	for (int i = 0; i < MaxEnemyNum_; i++)
	{
		if (isAlive_[MaxEnemyNum_])
		{
			return;
		}

		else
		{

		}
	}

	Ready(*camera_);
}

void Enemy::Draws()
{
	for (int i = 0; i < MaxEnemyNum_; i++)
	{
		Novice::DrawBox(
			static_cast<int>(pos_[i].x ),
			static_cast<int>(pos_[i].y + i * 30),
			static_cast<int>(32),
			static_cast<int>(32),
			0.0f,
			0xFFFFFFFF,
			kFillModeSolid
		);
	}
}
