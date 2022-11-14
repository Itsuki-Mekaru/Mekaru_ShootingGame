#pragma once
#include "SphereCollider.h"

class CharaBase : public SphereCollider
{
protected:
    class BulletsBase** bullets = nullptr;  // ���˂���e
    Location2D speed;   // �ړ����x
    int* image = nullptr; // �`�悷��摜

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