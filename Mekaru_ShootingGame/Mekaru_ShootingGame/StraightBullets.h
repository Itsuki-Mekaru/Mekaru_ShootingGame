#pragma once
#include "BulletsBase.h"
class StraightBullets : public BulletsBase
{
private:
    int image;  // 一旦放置

public:
    StraightBullets(T_Location location, T_Location speed = T_Location{0, 2});  // コンストラクタ

public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual bool isDeath() override;
};

