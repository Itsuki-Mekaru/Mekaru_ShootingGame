#pragma once
#include "BulletsBase.h"
class StraightBullets : public BulletsBase
{
private:
    int image;  // 一旦放置

public:
    StraightBullets(Location2D location);  // コンストラクタ

public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual bool isDeath() override;
};

