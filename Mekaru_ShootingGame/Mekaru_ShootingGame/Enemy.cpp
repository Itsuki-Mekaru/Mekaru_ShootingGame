#include "DxLib.h"
#include "Enemy.h"

Enemy::Enemy(T_Location location, float radius)
    : SphereCollider(location, radius)
{
    hp = 10;
    point = 10;

    speed = T_Location{0, 0.5};

    bullets = new BulletsBase * [30];
    for(int i = 0; i < 30; i++)
    {
        bullets[i] = nullptr;
    }
}

void Enemy::Update()
{
    T_Location newLocation = GetLocation();
    newLocation.y += speed.y;
    SetLocation(newLocation);
}

void Enemy::Draw()
{
    DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));
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