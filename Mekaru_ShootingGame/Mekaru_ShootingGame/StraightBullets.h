#pragma once
#include "BulletsBase.h"
class StraightBullets : public BulletsBase
{
private:
    int image;  // 一旦放置

public:
    StraightBullets(T_Location location);  // コンストラクタ

public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual bool isDeath() override;
};

