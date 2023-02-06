#pragma once
#include "CharaBase.h"

struct T_MoveInformation
{
    int pattern;    // 行動パターン
    T_Location destination; // 目的地
    int nextArrayNum;   // 次の配列番号
    int waitFrameTime;  // 待ち時間
    int attackType;  // 攻撃の種類
};

class Enemy : public CharaBase, public SphereCollider
{
private:
    int hp;
    int point;
    int WaitCount;
    int shotNum;

    T_MoveInformation moveInfo[5] = {};
    int current = 0;
    int waitTime = 0;

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
    void inputCSV();
    void Move();
};

