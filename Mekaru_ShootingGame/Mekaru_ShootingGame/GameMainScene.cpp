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
                // 弾のダメージをエネミーに与える
                enemy[EnemyCount]->Hit(bullets[bulletsCount]->GetDamage());

                // プレイヤーの弾とエネミーが当たった
                player->Hit(bulletsCount);  // 弾の削除
                bullets = player->GetBullets();
                bulletsCount--;

                // エネミーのHPがゼロ以下であれば、エネミーを消す
                if(enemy[EnemyCount]->HpCheck())
                {
                    // エネミーを消したとき、プレイヤーのスコアに、
                    // エネミーのポイントを加算する
                    player->addScore(enemy[EnemyCount]->GetPoint());

                    delete enemy[EnemyCount];
                    enemy[EnemyCount] = nullptr;

                    for(int i = (EnemyCount + 1); i < 10; i++)
                    {
                        if(enemy[i] == nullptr)
                        {
                            break;
                        }
                        enemy[i - 1] = enemy[i];
                        enemy[i] = nullptr;
                    }
                }

                
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