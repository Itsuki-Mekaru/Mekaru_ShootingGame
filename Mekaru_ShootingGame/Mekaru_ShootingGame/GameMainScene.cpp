#include "DxLib.h"
#include "GameMainScene.h"
#include "TitleScene.h"
#include "GameOverScene.h"

#include "HpPotion.h"

AbstractScene* GameMainScene::Update()
{

    if(enemyDeath || playerDeath)
    {
        waittime++;
        if(300 <= waittime)
        {
            if(playerDeath)
            {
                return dynamic_cast<AbstractScene*>(new GameOverScene());
            }
            else
            {
                return dynamic_cast<AbstractScene*>(new TitleScene());
            }
            
        }
    }
    else
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
                        for(int i = 0; i < 10; i++)
                        {
                            if(items[i] == nullptr)
                            {
                                items[i] = new HpPotion(enemy[EnemyCount]->GetLocation());
                                break;
                            }
                        }

                        // エネミーを消したとき、プレイヤーのスコアに、
                        // エネミーのポイントを加算する
                        player->addScore(enemy[EnemyCount]->GetPoint());
                        enemyDeath = true;

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

        for(int EnemyCount = 0; EnemyCount < 10; EnemyCount++)
        {
            if(enemy[EnemyCount] == nullptr)
            {
                break;
            }
            BulletsBase** enemyBullet = enemy[EnemyCount]->GetBullets();

            for(int bulletsCount = 0; bulletsCount < 30; bulletsCount++)
            {
                if(enemyBullet[bulletsCount] == nullptr)
                {
                    break;
                }

                if(enemyBullet[bulletsCount]->HitSphere(player))
                {
                    // 弾とプレイヤーが当たってる
                    player->Hit(enemyBullet[bulletsCount]);
                    playerDeath = player->LifeCheck();

                    enemy[EnemyCount]->DeleteBullet(bulletsCount);
                    bulletsCount--;
                }
            }
        }
    }

    for(int i = 0; i < 10; i++)
    {
        if(items[i] == nullptr)
        {
            break;
        }
        items[i]->Update();
    }

    // アイテムとプレイヤーの当たり判定
    for(int itemCount = 0; itemCount < 10; itemCount++)
    {
        if(items[itemCount] == nullptr)
        {
            break;
        }

        if(player->HitSphere(items[itemCount]))
        {
            player->Hit(items[itemCount]);

            delete items[itemCount];
            items[itemCount] = nullptr;
            for(int i = itemCount + 1; i < 10; i++)
            {
                if(items[i] == nullptr)
                {
                    break;
                }
                items[i - 1] = items[i];
                items[i] = nullptr;
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

    for(int i = 0; i < 10; i++)
    {
        if(items[i] == nullptr)
        {
            break;
        }
        items[i]->Draw();
    }
}