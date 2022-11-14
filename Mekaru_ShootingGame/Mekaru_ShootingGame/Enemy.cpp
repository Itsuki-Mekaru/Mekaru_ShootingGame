#include <math.h>
#include "DxLib.h"
#include "Enemy.h"

Enemy::Enemy(Location2D location, int radius)
    : CharaBase(location, radius), hp(10), point(10)
{
    speed =  Location2D{ 0.f, 0.5f };
    bullets = new BulletsBase * [30];
    for(int i = 0; i < 30; i++)
    {
        bullets[i] = nullptr;
    }
}

void Enemy::Update()
{
    Location2D newLocation = GetLocation();
    newLocation.y += speed.y;
    SetLocation(newLocation);
}

void Enemy::Draw()
{
    DrawCircle(static_cast<int>(floorf(GetLocation().x)), static_cast<int>(floorf(GetLocation().y)), GetRadius(), GetColor(255, 0, 255));
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