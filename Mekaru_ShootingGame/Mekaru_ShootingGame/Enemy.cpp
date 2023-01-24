#include "DxLib.h"
#include "Enemy.h"
#include "StraightBullets.h"
#include "CircleBullet.h"

struct ENEMY_MOVE
{
    int pattern;
    int waitTime;
    T_Location location;
    int next;
};

ENEMY_MOVE MovePttarn[6] = {
    {0,  0,  640.f, 150.f},
    {1, 60,    0.f,   0.f},
    {0,  0,1200.4f, 150.f},
    {1, 60,    0.f,   0.f},
    {0,  0,  80.2f, 150.f},
    {1, 60,    0.f,   0.f}
};

int current = 0;
int waitTime = 0;

Enemy::Enemy(T_Location location)
    : CharaBase(location, 20.f, T_Location{ 1, 2 })
    , hp(10), point(10), shotNum(0)
{
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

    switch(MovePttarn[current].pattern)
    {
        case 0:
            Move();
            break;

        case 1:
            waitTime++;
            if(MovePttarn[current].waitTime <= waitTime)
            {
                waitTime = 0;
                current = MovePttarn[current].next;
            }
            break;

        default:
            break;
    }

    int bulletCount;
    for(bulletCount = 0; bulletCount < 30; bulletCount++)
    {
        if(bullets[bulletCount] == nullptr)
        {
            break;
        }
        bullets[bulletCount]->Update();

        if(bullets[bulletCount]->isScreenOut())
        {
            DeleteBullet(bulletCount, _ENEMY_BULLET_ALL_);
            bulletCount--;
        }
    }

    if(MovePttarn[current].attackType != 0)
    {
        WaitCount++;
        if(ATTACK_INTERVAL <= WaitCount)
        {
            if(bulletCount < 30 && bullets[bulletCount] == nullptr)
            {
                WaitCount = 0;
                if(moveInfo[current].attackType == 1)
                {
                    bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0, 2 });
                }
                else if(moveInfo[current].attackType == 2)
                {
                    shotNum++;
                    bullets[bulletCount] = new CircleBullet(GetLocation(), 2.f, (20 * shotNum));
                }
            }
        }
    }
}

void Enemy::Update()
{
    //T_Location newLocation = GetLocation();
    //newLocation.y += speed.y;
    //SetLocation(newLocation);

    Move();

    int bulletCount;
    for(bulletCount = 0; bulletCount < _ENEMY_BULLET_ALL_; bulletCount++)
    {
        if(bullets[bulletCount] == nullptr)
        {
            break;
        }
        bullets[bulletCount]->Update();

        // ‰æ–ÊŠO‚És‚Á‚½‚ç’e‚ðÁ‚·
        if(bullets[bulletCount]->isScreenOut())
        {
            DeleteBullet(bulletCount, _ENEMY_BULLET_ALL_);
            bulletCount--;
        }
    }

    if(bulletCount < _ENEMY_BULLET_ALL_ && bullets[bulletCount] == nullptr)
    {
        // ’e–‹‚ðì‚ë‚¤
        bullets[bulletCount] =
            new CircleBullet(GetLocation(), 2.f, (20 * shotNum));
        shotNum++;
        //bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0, 2 });
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

    switch(MovePttarn[current].pattern)
    {
        case 0:
            break;

            if((nextLocation.y == MovePttarn[current].location.y) &&
               (nextLocation.x == MovePttarn[current].location.x))
            {
                current++;

                int maxsize = (sizeof(MovePttarn) / sizeof(*MovePttarn));
                if(current == maxsize)
                {
                    current = 0;
                }
            }
            else
            {
                if(nextLocation.y != MovePttarn[current].location.y)
                {
                    if(nextLocation.y < MovePttarn[current].location.y)
                    {
                        nextLocation.y += speed.y;
                        if((GetLocation().y <= MovePttarn[current].location.y) &&
                           (MovePttarn[current].location.y <= nextLocation.y))
                        {
                            nextLocation.y = MovePttarn[current].location.y;
                        }
                    }
                    else
                    {
                        nextLocation.y -= speed.y;
                        if((nextLocation.y <= MovePttarn[current].location.y) &&
                           (MovePttarn[current].location.y <= GetLocation().y))
                        {
                            nextLocation.y = MovePttarn[current].location.y;
                        }
                    }
                }

                if(nextLocation.x != MovePttarn[current].location.x)
                {
                    if(nextLocation.x < MovePttarn[current].location.x)
                    {
                        nextLocation.x += speed.x;
                        if((GetLocation().x <= MovePttarn[current].location.x) &&
                           (MovePttarn[current].location.x <= nextLocation.x))
                        {
                            nextLocation.x = MovePttarn[current].location.x;
                        }
                    }
                    else
                    {
                        nextLocation.x -= speed.x;
                        if((nextLocation.x <= MovePttarn[current].location.x) &&
                           (MovePttarn[current].location.x <= GetLocation().x))
                        {
                            nextLocation.x = MovePttarn[current].location.x;
                        }
                    }
                }

        case 1:
            break;

        default:
    };

    
    }

    SetLocation(nextLocation);
}