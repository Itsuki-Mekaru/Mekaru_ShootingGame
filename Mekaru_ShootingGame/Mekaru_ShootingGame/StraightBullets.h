#pragma once
#include "BulletsBase.h"
class StraightBullets : public BulletsBase
{
private:
    int image;  // ��U���u

public:
    StraightBullets(T_Location location, T_Location speed = T_Location{0, 2});  // �R���X�g���N�^

public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual bool isDeath() override;
};

