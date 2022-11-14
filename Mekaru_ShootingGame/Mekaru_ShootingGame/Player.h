#pragma once
#include "CharaBase.h"

class Player : public CharaBase
{
private:
    int score;  // åªç›ÉXÉRÉA
    int life;   // HP

public:
    Player(Location2D location, int radius);

public:
    void Update() override;
    void Draw() override;
    void Hit() override;
    void Hit(int bulletsCount);
    bool LifeCheck();
    int GetScore();
    void addScore(int point);
};

