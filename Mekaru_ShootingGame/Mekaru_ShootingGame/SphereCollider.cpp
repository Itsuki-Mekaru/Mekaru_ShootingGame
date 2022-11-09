#include "SphereCollider.h"
#include <math.h>

SphereCollider::SphereCollider(Location2D location, float radius)
{
    this->location = location;
    this->radius = radius;
}

bool SphereCollider::HitSphere(SphereCollider* collider)
{
    // 円と円の当たり判定
    // 自分から相手へのベクトルを求める
    Location2D a = collider->GetLocation();
    Location2D location = this->GetLocation() - collider->GetLocation();

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

Location2D SphereCollider::GetLocation()
{
    return location;
}

void SphereCollider::SetLocation(Location2D value)
{
    location.x = value.x;
    location.y = value.y;
}