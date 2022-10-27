#pragma once
#include "CharaBase.h"

class Enemy : public CharaBase, public SphereCollider
{
private:
    int hp;
    int point;

public:
    Enemy(T_Location location, float radius);

public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual void Hit() override;
    bool HpCheck();
    int GetPoint();
};

