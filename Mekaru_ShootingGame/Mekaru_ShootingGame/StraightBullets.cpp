#include "DxLib.h"
#include "StraightBullets.h"
#include "common.h"

StraightBullets::StraightBullets(T_Location location, T_Location speed)
    : BulletBase(location, 5.f, 1, speed)
{
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

bool StraightBullets::isScreenOut()
{
    bool ret = ((GetLocation().y + GetRadius()) <= 0);
    if(ret)
    {
        return ret;
    }

    ret = (SCREEN_HEIGHT <= (GetLocation().y - GetRadius()));
    return ret;
}