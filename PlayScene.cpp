#include "PlayScene.h"

PlayScene::PlayScene(CommonData* cd) : Scene(cd)
{
	camera_ = new Camera();
	gameover_ = new GameOver(cd_);
	gameclear_ = new GameClear(cd_);
}

Scene* PlayScene::Update()
{
	if (cd_->keys[DIK_F] && !cd_->preKeys[DIK_F])
	{
		cd_->se_[int(SE::test)] = true;

		return gameover_;
	}

	if (cd_->keys[DIK_E] && !cd_->preKeys[DIK_E])
	{
		cd_->se_[int(SE::test)] = true;

		return gameclear_;
	}

	return nullptr;
}

void PlayScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "GameScene");
}
