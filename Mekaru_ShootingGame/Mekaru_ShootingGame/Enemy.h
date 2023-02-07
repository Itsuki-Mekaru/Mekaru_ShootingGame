#pragma once
#include "CharaBase.h"

#define _ENEMY_BULLET_ALL_ 300

struct T_MoveInformation
{
    int pattern;            // �s���p�^�[��
    T_Location destination; // �ړI�n
    int nextArrayNum;       // ���̔z��ԍ�
    int waitFrameTime;      // �҂�����
    int attackType;         // �U���̎��
};

class Enemy : public CharaBase
{
private:
    int hp;
    int point;
    int shotNum;
    T_MoveInformation moveInfo[5] = {};

    int current = 0;
    int waitTime = 0;

    void inputCSV();
public:
    Enemy(T_Location location);

public:
    virtual void Update() override;
    virtual void Draw() override;
    virtual void Hit(int damage) override;
    bool HpCheck();
    int GetPoint();
    void Move();
};

