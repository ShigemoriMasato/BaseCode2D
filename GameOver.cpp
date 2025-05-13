#include "GameOver.h"

GameOver::GameOver(CommonData* cd) : Scene(cd)
{
	/*title_ = new Title(cd);*/
}

Scene* GameOver::Update()
{
	if (cd_->keys[DIK_F] && !cd_->preKeys[DIK_F])
	{
		cd_->se_[int(SE::test)] = true;

		/*return title_;*/
	}

	return nullptr;
}

void GameOver::Draw()
{
	Novice::ScreenPrintf(0, 0, "GameOver");
}
