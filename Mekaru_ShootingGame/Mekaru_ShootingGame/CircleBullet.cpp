#include "DxLib.h"
#include "CircleBullet.h"

#define _USE_MATH_DEFINES
#include <math.h>

CircleBullet::CircleBullet(T_Location location, float speed, float radAngle, int num)
    : BulletBase(location, 5.f, 1, T_Location{0,0})
{
    int b = (30 * num) % 360;
    double a = (M_PI / 180) * b;
    float x = (abs(b) == 90 || b == 270) ? 0 : cos(a);
    float y = (abs(b) == 180) ? 0 : sin(a);

    this->speed = T_Location{static_cast<float>(x), static_cast<float>(y)};
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

bool CircleBullet::isScreenOut()
{
    bool ret = ((GetLocation().y + GetRadius()) <= 0);
    if(ret)
    {
        return ret;
    }

    ret = (SCREEN_HEIGHT <= (GetLocation().y - GetRadius()));
    if(ret)
    {
        return ret;
    }

    ret = ((GetLocation().x + GetRadius()) <= 0);
    if(ret)
    {
        return ret;
    }

    ret = (SCREEN_WIDTH <= (GetLocation().x - GetRadius()));
    return ret;
}