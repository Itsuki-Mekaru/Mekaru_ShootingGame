#pragma once
#include "BulletsBase.h"
class StraightBullets : public BulletsBase
{
public:
    StraightBullets(T_Location location, T_Location speed = T_Location{ 0, -2 });

public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual bool isScreenOut() override;
};

