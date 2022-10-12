#pragma once
#include "SphereCollider.h"

class CharaBase
{
private:
    T_Location speed;   // 移動速度

protected:
    int* image = nullptr; // 描画する画像
    //変数：
    //    ・bullets(ポインタ配列)

public:
    virtual ~CharaBase();

public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    virtual void Hit() = 0;

    T_Location GetSpeed();
    void SetSpeed(T_Location speed);
    //関数：
    //    ・GetBullets()
};