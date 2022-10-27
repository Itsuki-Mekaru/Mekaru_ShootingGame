#include "SphereCollider.h"
#include <math.h>

SphereCollider::SphereCollider(T_Location location, float radius)
{
    this->location.x = location.x;
    this->location.y = location.y;

    this->radius = radius;
}

bool SphereCollider::HitSphere(SphereCollider* s)
{
    // 円と円の当たり判定
    // 自分から相手へのベクトルを求める
    T_Location location = s->GetLocation();
    float x = this->location.x - location.x;
    float y = this->location.y - location.y;

    // 絶対値に変換
    x = fabsf(x);
    y = fabsf(y);

    // ベクトルの大きさを取得　√(x*x) + (y*y) 
    float xy = (x * x) + (y * y);
    double vectorSize = sqrt(xy);

    // 自分の半径　＋　相手の半径　を取得
    float radius = this->radius + s->GetRadius();

    // ベクトルの大きさ　＜＝　合計の半径　の時当たってる
    bool ret = (vectorSize <= radius);
    return ret;
}

float SphereCollider::GetRadius()
{
    return radius;
}

T_Location SphereCollider::GetLocation()
{
    return location;
}

void SphereCollider::SetLocation(T_Location value)
{
    location.x = value.x;
    location.y = value.y;
}