#include"GameClear.h"
#include"Title.h"

GameClear::GameClear(CommonData* cd) : Scene(cd)
{
	//Title* title_ = new Title(cd);
}

Scene* GameClear::Update()
{
	if (cd_->keys[DIK_F] && !cd_->preKeys[DIK_F])
	{
		cd_->se_[int(SE::test)] = true;

		/*return title_;*/
	}

	return nullptr;
}

void GameClear::Draw()
{
	Novice::ScreenPrintf(0, 0, "GameClear");
}