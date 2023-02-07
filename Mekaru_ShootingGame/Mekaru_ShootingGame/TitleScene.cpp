#include "KeyManager.h"
#include "TitleScene.h"
#include "GameMainScene.h"
#include "DxLib.h"

TitleScene::TitleScene()
{
    SetFontSize(32);
}

void TitleScene::Update()
{
}

//描画に関することを実装する
void TitleScene::Draw() const
{
    DrawFormatString(400, 550, GetColor(255, 255, 0), "SPACE キーを押してゲームスタート");
}

// シーンの変更処理
AbstractScene* TitleScene::ChangeScene()
{
    if(KeyManager::OnKeyReleased(KEY_INPUT_SPACE))
    {
        return dynamic_cast<AbstractScene*>(new GameMainScene());
    }

    return this;
}