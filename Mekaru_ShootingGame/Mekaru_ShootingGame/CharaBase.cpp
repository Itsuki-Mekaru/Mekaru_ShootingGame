#include "CharaBase.h"
#include "BulletsBase.h"



CharaBase::CharaBase(Location2D location, int radius) : SphereCollider(location, radius)
{

}

CharaBase::~CharaBase()
{
    if(image != nullptr)
    {
        delete[] image;
    }
}

Location2D CharaBase::GetSpeed()
{
    return speed;
}

void CharaBase::SetSpeed(Location2D speed)
{
    this->speed.x = speed.x;
    this->speed.y = speed.y;
}

BulletsBase** CharaBase::GetBullets()
{
    return bullets;
}