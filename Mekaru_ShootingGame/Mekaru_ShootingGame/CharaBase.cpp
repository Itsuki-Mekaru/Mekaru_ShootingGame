#include "CharaBase.h"

CharaBase::~CharaBase()
{
    if(image != nullptr)
    {
        delete[] image;
    }
}

T_Location CharaBase::GetSpeed()
{
    return speed;
}

void CharaBase::SetSpeed(T_Location speed)
{
    this->speed.x = speed.x;
    this->speed.y = speed.y;
}

BulletsBase** CharaBase::GetBullets()
{
    return bullets;
}