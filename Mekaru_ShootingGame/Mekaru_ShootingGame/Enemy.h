#pragma once
#include "CharaBase.h"

class Enemy : public CharaBase, public SphereCollider
{
private:
    int hp;
    int point;
    int WaitCount;

public:
    Enemy(T_Location location, float radius);

public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual void Hit() override;
    virtual void Hit(int damage);
    bool HpCheck();
    int GetPoint();
    void DeleteBullet(int bulletCount);
};

