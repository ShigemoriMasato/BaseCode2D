#pragma once
#include"Scene.h"

class GameOver : public Scene
{
public:
	GameOver(CommonData* cd);
	~GameOver() = default;

	Scene* Update() override;
	void Draw() override;
};