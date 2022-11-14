#pragma once
#include "SphereCollider.h"

class CharaBase : public SphereCollider
{
protected:
    class BulletsBase** bullets = nullptr;  // 発射する弾
    Location2D speed;   // 移動速度
    int* image = nullptr; // 描画する画像

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