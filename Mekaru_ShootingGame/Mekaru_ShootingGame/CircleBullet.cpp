#include "DxLib.h"
#include "common.h"
#include "CircleBullet.h"

#define _USE_MATH_DEFINES
#include <math.h>

CircleBullet::CircleBullet(T_Location location, float speed, int degAngle)
    :BulletsBase(location, 5.f, 1, T_Location{ 0, 0 })
{
    int deg = degAngle % 360;
    double rad = (M_PI / 180) * deg;
    float x = (abs(deg) == 90 || abs(deg) == 270) ? 0 : cos(rad);
    float y = sin(rad);

    this->speed = T_Location{ (speed * x), (speed * y) };
}

void CircleBullet::Update()
{
    T_Location newLocation = GetLocation();
    newLocation.y += speed.y;
    newLocation.x += speed.x;
    SetLocation(newLocation);
}

void CircleBullet::Draw()
{
    DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 255, 0));
}

bool CircleBullet::isDeath()
{
    float y = GetLocation().y + GetRadius();
    if(y <= 0)
    {
        return true;
    }

    y = GetLocation().y - GetRadius();
    if(SCREEN_HEIGHT <= y)
    {
        return true;
    }

    float x = GetLocation().x + GetRadius();
    if(x <= 0)
    {
        return true;
    }

    x = GetLocation().x - GetRadius();
    if(SCREEN_WIDTH <= x)
    {
        return true;
    }

    return false;
}