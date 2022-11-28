#pragma once
#include "BulletsBase.h"

class CircleBullet : public BulletBase
{
public:
    CircleBullet(T_Location location, float speed, float radAngle, int num);

public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual bool isScreenOut() override;
};

