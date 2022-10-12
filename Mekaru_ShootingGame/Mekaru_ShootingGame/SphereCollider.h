#pragma once
#include "common.h"

class SphereCollider
{
private:
    T_Location location;    // �i���S���W�j
    float radius;           // ���a

public:
    SphereCollider(T_Location location, float radius);

public:
    bool HitSphere(const SphereCollider* collider) const;    // SphereCollider�^���m�̓����蔻��
    
    T_Location GetLocation() const; // ���S���W�̎擾
    void SetLocation(T_Location location);  // ���S���W�̐ݒ�
    
    float GetRadius() const;    // ���a�̎擾
};