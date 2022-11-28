#include "StraightBullets.h"
#include "DxLib.h"

StraightBullets::StraightBullets(T_Location location, T_Location speed)
    : BulletsBase(location, 5.f, 1, speed)
{
    image = 0;
}

void StraightBullets::Update()
{
    T_Location newLocation = GetLocation();
    newLocation.y += speed.y;
    SetLocation(newLocation);
}

void StraightBullets::Draw()
{
    DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
}

bool StraightBullets::isDeath()
{
    float y = GetLocation().y + GetRadius();
    if(y <= 0)
    {
        return true;
    }

    if(720 <= y)
    {
        return true;
    }

    return false;
}