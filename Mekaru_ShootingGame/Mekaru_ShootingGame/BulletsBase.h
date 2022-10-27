#pragma once
#include "SphereCollider.h"

class BulletsBase : public SphereCollider
{
protected:
    int damage;
    T_Location speed;

public: 
    BulletsBase(T_Location location, float radius, int damage, T_Location speed)
        : SphereCollider(location, radius), damage(damage), speed(speed)
    {
    }

public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual bool isDeath() = 0;
    virtual int GetDamage();
};

