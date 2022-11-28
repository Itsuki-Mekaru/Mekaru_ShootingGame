#include "BulletsBase.h"

BulletBase::BulletBase(T_Location location, float radius, int damage, T_Location speed)
    :SphereCollider(location, radius), damage(damage), speed(speed)
{
}

int BulletBase::GetDamage()
{
    return damage;
}