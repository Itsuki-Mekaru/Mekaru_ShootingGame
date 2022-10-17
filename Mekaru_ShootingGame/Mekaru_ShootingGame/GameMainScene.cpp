#include "DxLib.h"
#include "GameMainScene.h"

AbstractScene* GameMainScene::Update()
{
    player->Update();
    // 自分自身のポインタ
    return this;
}

void GameMainScene::Draw() const
{
    player->Draw();
}