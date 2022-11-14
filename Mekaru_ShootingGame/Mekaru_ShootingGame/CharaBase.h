#pragma once
#include "SphereCollider.h"

class CharaBase : public SphereCollider
{
protected:
    class BulletsBase** bullets = nullptr;  // ”­ŽË‚·‚é’e
    Location2D speed;   // ˆÚ“®‘¬“x
    int* image = nullptr; // •`‰æ‚·‚é‰æ‘œ

public:
    CharaBase(Location2D location, int radius);
    virtual ~CharaBase();

public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void Hit() = 0;

    Location2D GetSpeed();
    void SetSpeed(Location2D speed);
    BulletsBase** GetBullets();
};