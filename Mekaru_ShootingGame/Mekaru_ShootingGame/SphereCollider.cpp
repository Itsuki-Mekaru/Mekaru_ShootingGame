#include "SphereCollider.h"
#include <math.h>

SphereCollider::SphereCollider(Location2D location, int radius) : location(location), radius(radius)
{}

bool SphereCollider::HitSphere(SphereCollider* collider)
{
    // 円と円の当たり判定
    // 自分から相手へのベクトルを求める
    Location2D location = this->GetLocation() - collider->GetLocation();

    // ベクトルの大きさを取得　√(x*x) + (y*y) 
    float vectorSize = location.GetLength();

    // 自分の半径　＋　相手の半径　を取得
    float radius = static_cast<float>(this->radius + collider->GetRadius());

    // ベクトルの大きさ　＜＝　合計の半径　の時当たってる
    bool ret = (vectorSize <= radius);
    return ret;
}

int SphereCollider::GetRadius()
{
    return radius;
}

Location2D SphereCollider::GetLocation()
{
    return location;
}

void SphereCollider::SetLocation(Location2D value)
{
    location = value;
}