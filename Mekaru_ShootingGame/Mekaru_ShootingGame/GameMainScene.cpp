#include "DxLib.h"
#include "GameMainScene.h"

AbstractScene* GameMainScene::Update()
{
    player->Update();
    for(int i = 0; i < 10; i++)
    {
        if(enemy[i] == nullptr)
        {
            break;
        }
        enemy[i]->Update();
    }

    BulletsBase** bullets = player->GetBullets();
    for(int bulletsCount = 0; bulletsCount < 30; bulletsCount++)
    {
        if(bullets[bulletsCount] == nullptr)
        {
            break;
        }
        for(int EnemyCount = 0; EnemyCount < 10; EnemyCount++)
        {
            if(enemy[EnemyCount] == nullptr)
            {
                break;
            }
            if(bullets[bulletsCount]->HitSphere(enemy[EnemyCount]))
            {
                // �v���C���[�̒e�ƃG�l�~�[����������
                // �e�̃_���[�W���G�l�~�[�ɗ^����
                // �e������
                // �G�l�~�[��HP���[���ȉ��ł���΁A�G�l�~�[������
                // �G�l�~�[���������Ƃ��A�v���C���[�̃X�R�A�ɁA
                // �G�l�~�[�̃|�C���g�����Z����
            }
        }
    }

    // �������g�̃|�C���^
    return this;
}

void GameMainScene::Draw() const
{
    player->Draw();
    for(int i = 0; i < 10; i++)
    {
        if(enemy[i] == nullptr)
        {
            break;
        }
        enemy[i]->Draw();
    }
}