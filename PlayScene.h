#pragma once  
#include<Novice.h>  

#include"Camera.h"  
#include "Scene.h"  
#include "GameOver.h"  // Ensure this header file is included to define the GameOver class  
#include "GameClear.h"  

class PlayScene : public Scene
{
public:
	PlayScene(CommonData* cd);
	~PlayScene() = default;

	Scene* Update() override;
	void Draw() override;

private:

	Camera* camera_;

	GameOver* gameover_;  // Ensure GameOver is properly declared in the included header  
	GameClear* gameclear_;
};
