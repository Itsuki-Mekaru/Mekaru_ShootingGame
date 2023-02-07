#include "DxLib.h"
#include "Enemy.h"
#include "StraightBullets.h"
#include "CircleBullet.h"

void Enemy::inputCSV()
{
    FILE* fp; // FILE型構造体
    errno_t error;  // fopen_sのエラー確認

    error = fopen_s(&fp, "../data/T_MoveInformation.csv", "r");
    if(error != 0)
    {
        // エラー発生
        return;
    }
    else
    {
        // ファイルを開いた
        char line[100];
        for(int i = 0; fgets(line, 100, fp) != NULL; i++)
        //while(fgets(line, 100, fp) != NULL)
        {
            sscanf_s(line, "%d, %f, %f, %d, %d, %d", 
                     &moveInfo[i].pattern,
                     &moveInfo[i].destination.x,
                     &moveInfo[i].destination.y,
                     &moveInfo[i].nextArrayNum,
                     &moveInfo[i].waitFrameTime,
                     &moveInfo[i].attackType
                    );
        }
        return;
    }

    fclose(fp); // ファイルを閉じる
}


Enemy::Enemy(T_Location location)
    : CharaBase(location, 20.f, T_Location{ 1, 2 })
    , hp(10), point(10), shotNum(0)
{
    inputCSV();

    bullets = new BulletBase * [_ENEMY_BULLET_ALL_];
    for(int i = 0; i < _ENEMY_BULLET_ALL_; i++)
    {
        bullets[i] = nullptr;
    }
}

void Enemy::Update()
{
    //T_Location newLocation = GetLocation();
    //newLocation.y += speed.y;
    //SetLocation(newLocation);

    switch(moveInfo[current].pattern)
    {
        case 0:
            Move();
        break;
        
        case 1:
            waitTime++;
            if(moveInfo[current].waitFrameTime <= waitTime)
            {
                waitTime = 0;
                current = moveInfo[current].nextArrayNum;
            }
        break;
    }
    

    int bulletCount;
    for(bulletCount = 0; bulletCount < _ENEMY_BULLET_ALL_; bulletCount++)
    {
        if(bullets[bulletCount] == nullptr)
        {
            break;
        }
        bullets[bulletCount]->Update();

        // 画面外に行ったら弾を消す
        if(bullets[bulletCount]->isScreenOut())
        {
            DeleteBullet(bulletCount, _ENEMY_BULLET_ALL_);
            bulletCount--;
        }
    }

    if(moveInfo[current].attackType != 0)
    {
        if(bulletCount < _ENEMY_BULLET_ALL_ && bullets[bulletCount] == nullptr)
        {
            if(moveInfo[current].attackType == 1)
            {
                bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0, 2 });
            }
            else if(moveInfo[current].attackType == 2)
            {
                shotNum++;
                bullets[bulletCount] =
                    new CircleBullet(GetLocation(), 4.f, (20 * shotNum));
            }
        }
    }

#define _DEBUG_MODE_PLAYE_

#ifdef _DEBUG_MODE_PLAYE_
    DrawFormatString(10, 10, GetColor(255, 255, 255), "x = %lf", GetLocation().x);
    DrawFormatString(10, 30, GetColor(255, 255, 255), "y = %lf", GetLocation().y);
#endif
}

void Enemy::Draw()
{
    DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));

    for(int bulletCount = 0; bulletCount < _ENEMY_BULLET_ALL_; bulletCount++)
    {
        if(bullets[bulletCount] == nullptr)
        {
            break;
        }
        bullets[bulletCount]->Draw();
    }
}

void Enemy::Hit(int damage)
{
    if(0 < damage)
    {
        hp -= damage;
        if(hp < 0)
        {
            hp = 0;
        }
    }
}

bool Enemy::HpCheck()
{
    bool ret = (hp <= 0);
    return ret;
}

int Enemy::GetPoint()
{
    return point;
}

void Enemy::Move()
{
    T_Location nextLocation = GetLocation();

    if((nextLocation.y == moveInfo[current].destination.y) &&
       (nextLocation.x == moveInfo[current].destination.x))
    {
        current = moveInfo[current].nextArrayNum;
    }
    else
    {
        if(nextLocation.y != moveInfo[current].destination.y)
        {
            if(nextLocation.y < moveInfo[current].destination.y)
            {
                nextLocation.y += speed.y;
                if((GetLocation().y <= moveInfo[current].destination.y) &&
                   (moveInfo[current].destination.y <= nextLocation.y))
                {
                    nextLocation.y = moveInfo[current].destination.y;
                }
            }
            else
            {
                nextLocation.y -= speed.y;
                if((nextLocation.y <= moveInfo[current].destination.y) &&
                   (moveInfo[current].destination.y <= GetLocation().y))
                {
                    nextLocation.y = moveInfo[current].destination.y;
                }
            }
        }

        if(nextLocation.x != moveInfo[current].destination.x)
        {
            if(nextLocation.x < moveInfo[current].destination.x)
            {
                nextLocation.x += speed.x;
                if((GetLocation().x <= moveInfo[current].destination.x) &&
                   (moveInfo[current].destination.x <= nextLocation.x))
                {
                    nextLocation.x = moveInfo[current].destination.x;
                }
            }
            else
            {
                nextLocation.x -= speed.x;
                if((nextLocation.x <= moveInfo[current].destination.x) &&
                   (moveInfo[current].destination.x <= GetLocation().x))
                {
                    nextLocation.x = moveInfo[current].destination.x;
                }
            }
        }
    }

    SetLocation(nextLocation);
}