#include "DxLib.h"
#include "Enemy.h"
#include "StraightBullets.h"
#include "CircleBullet.h"

#define ATTACK_INTERVAL 5

Enemy::Enemy(T_Location location, float radius)
    : SphereCollider(location, radius)
{
    hp = 10;
    point = 10;
    WaitCount = 99;
    shotNum = 0;

    speed = T_Location{ 0, 0.5 };

    bullets = new BulletsBase * [30];
    for(int i = 0; i < 30; i++)
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
    for(bulletCount = 0; bulletCount < 30; bulletCount++)
    {
        if(bullets[bulletCount] == nullptr)
        {
            break;
        }
        bullets[bulletCount]->Update();

        if(bullets[bulletCount]->isDeath())
        {
            DeleteBullet(bulletCount);
            bulletCount--;
        }
    }

    WaitCount++;
    if(ATTACK_INTERVAL <= WaitCount)
    {
        if(bulletCount < 30 && bullets[bulletCount] == nullptr)
        {
            WaitCount = 0;
            shotNum++;
            bullets[bulletCount] = new CircleBullet(GetLocation(), 2.f, (20 * shotNum));

            //bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0, 2 });
        }
    }
}

void Enemy::Draw()
{
    DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));

    int bulletCount;
    for(bulletCount = 0; bulletCount < 30; bulletCount++)
    {
        if(bullets[bulletCount] == nullptr)
        {
            break;
        }
        bullets[bulletCount]->Draw();
    }
}

void Enemy::Hit()
{

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

void Enemy::DeleteBullet(int bulletCount)
{
    delete bullets[bulletCount];
    bullets[bulletCount] = nullptr;

    for(int i = (bulletCount + 1); i < 30; i++)
    {
        if(bullets[i] == nullptr)
        {
            break;
        }
        bullets[i - 1] = bullets[i];
        bullets[i] = nullptr;
    }
}