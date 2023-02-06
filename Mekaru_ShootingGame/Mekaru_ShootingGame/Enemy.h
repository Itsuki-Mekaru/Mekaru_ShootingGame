#pragma once
#include "CharaBase.h"

struct T_MoveInformation
{
    int pattern;    // �s���p�^�[��
    T_Location destination; // �ړI�n
    int nextArrayNum;   // ���̔z��ԍ�
    int waitFrameTime;  // �҂�����
    int attackType;  // �U���̎��
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

