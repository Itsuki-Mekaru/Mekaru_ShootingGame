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

//�`��Ɋւ��邱�Ƃ���������
void TitleScene::Draw() const
{
    DrawFormatString(400, 550, GetColor(255, 255, 0), "SPACE �L�[�������ăQ�[���X�^�[�g");
}

// �V�[���̕ύX����
AbstractScene* TitleScene::ChangeScene()
{
    if(KeyManager::OnKeyReleased(KEY_INPUT_SPACE))
    {
        return dynamic_cast<AbstractScene*>(new GameMainScene());
    }

    return this;
}