#include "GameOverScene.h"
#include "KeyManager.h"
#include "TitleScene.h"

int x = 0;
int y = 0;

//�`��ȊO�̍X�V����������
AbstractScene* GameOverScene::Update()
{
    if(KeyManager::OnRelease(KEY_INPUT_SPACE))
    {
        return dynamic_cast<AbstractScene*>(new TitleScene());
    }

    if(KeyManager::OnPressed(KEY_INPUT_W))
    {
        y--;
    }
    if(KeyManager::OnPressed(KEY_INPUT_A))
    {
        x--;
    }
    if(KeyManager::OnPressed(KEY_INPUT_S))
    {
        y++;
    }
    if(KeyManager::OnPressed(KEY_INPUT_D))
    {
        x++;
    }
    return this;
}

//�`��Ɋւ��邱�Ƃ���������
void GameOverScene::Draw() const
{
    //DrawFormatString(0, 0, GetColor(255, 0, 0), "x = %d : y = %d", x, y);
    SetFontSize(64);
    DrawFormatString(500, 210, GetColor(255, 255, 0), "GAME OVER");
    SetFontSize(32);
    DrawFormatString(400, 550, GetColor(255, 255, 0), "SPACE �L�[�������ăQ�[���X�^�[�g");
}