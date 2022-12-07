#include "DxLib.h"
#include "Enemy.h"
#include "StraightBullets.h"
#include "CircleBullet.h"

#define _ENEMY_BULLET_ALL_ 100

Enemy::Enemy(T_Location location)
    : CharaBase(location, 20.f, T_Location{ 0, 0.5 })
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