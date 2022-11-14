#pragma once
#include "CharaBase.h"

class Enemy : public CharaBase
{
private:
    int hp;
    int point;

public:
    Enemy(Location2D location, int radius);

public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual void Hit() override;
    virtual void Hit(int damage);
    bool HpCheck();
    int GetPoint();
};

