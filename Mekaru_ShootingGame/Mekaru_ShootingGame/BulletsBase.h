#pragma once
#include "SphereCollider.h"

class BulletsBase : public SphereCollider
{
protected:
    int damage;
    Location2D speed;

public: 
    BulletsBase(Location2D location, int radius, int damage, Location2D speed)
        : SphereCollider(location, radius), damage(damage), speed(speed)
    {
    }

public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual bool isDeath() = 0;
    virtual int GetDamage();
};

