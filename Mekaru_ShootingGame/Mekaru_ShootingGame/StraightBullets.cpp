#include <math.h>
#include "DxLib.h"
#include "StraightBullets.h"

StraightBullets::StraightBullets(Location2D location)
    : BulletsBase(location, 5.f, 1, Location2D{0, 2})
{
    image = 0;
}

void StraightBullets::Update()
{
    Location2D newLocation = GetLocation();
    newLocation.y -= speed.y;
    SetLocation(newLocation);
}

void StraightBullets::Draw()
{
    DrawCircle(static_cast<int>(floorf(GetLocation().x)), static_cast<int>(floorf(GetLocation().y)), GetRadius(), GetColor(0, 255, 0));
}

bool StraightBullets::isDeath()
{
    float y = GetLocation().y + GetRadius();
    if(y <= 0)
    {
        return true;
    }

    return false;
}