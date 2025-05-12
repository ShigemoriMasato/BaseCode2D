#pragma once
#include"Scene.h"

class GameClear : public Scene
{
public:
	GameClear(CommonData* cd);
	~GameClear() = default;

	Scene* Update() override;
	void Draw() override;
};