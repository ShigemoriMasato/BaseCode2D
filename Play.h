#pragma once
#include "Scene.h"
class Play : public Scene
{
public:
	Play(CommonData* cd);
	~Play() = default;

	Scene* Update() override;
	void Draw() override;
};

