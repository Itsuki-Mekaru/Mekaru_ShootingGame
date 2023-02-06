#include "KeyManager.h"
#include "TitleScene.h"
#include "GameMainScene.h"

TitleScene::TitleScene()
{
    SetFontSize(32);
}

AbstractScene* TitleScene::Update()
{
    if(KeyManager::OnRelease(KEY_INPUT_SPACE))
    {
        return dynamic_cast<AbstractScene*>(new GameMainScene());
    }
    return this;
}

//�`��Ɋւ��邱�Ƃ���������
void TitleScene::Draw() const
{
    DrawFormatString(400, 550, GetColor(255, 255, 0), "SPACE �L�[�������ăQ�[���X�^�[�g");
}