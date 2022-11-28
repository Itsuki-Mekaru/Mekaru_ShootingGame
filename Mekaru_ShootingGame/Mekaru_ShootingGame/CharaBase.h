#pragma once
#include "SphereCollider.h"
#include "BulletsBase.h"

class CharaBase : public SphereCollider
{
protected:
    T_Location speed;
    BulletBase** bullets;
    int* image;

public:
    CharaBase(T_Location location, float radius, T_Location speed);

public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void Hit(int damage) = 0;
    BulletBase** GetBullets();
    void DeleteBullet(int bulletNum, int all);
};

