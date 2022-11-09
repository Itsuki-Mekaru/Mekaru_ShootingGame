#pragma once
#include "Location2D.h"

class SphereCollider
{
private:
    Location2D location;
    float radius;

public:
    SphereCollider(Location2D location, float radius);

public:
    bool HitSphere(SphereCollider* collider);   // �R���C�_�[���m�̃q�b�g����
    float GetRadius();
    Location2D GetLocation();
    void SetLocation(Location2D value);
};