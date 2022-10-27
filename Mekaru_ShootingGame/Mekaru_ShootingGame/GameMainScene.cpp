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
                // プレイヤーの弾とエネミーが当たった
                // 弾のダメージをエネミーに与える
                // 弾を消す
                // エネミーのHPがゼロ以下であれば、エネミーを消す
                // エネミーを消したとき、プレイヤーのスコアに、
                // エネミーのポイントを加算する
            }
        }
    }

    // 自分自身のポインタ
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