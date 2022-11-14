#include "SphereCollider.h"
#include <math.h>

SphereCollider::SphereCollider(Location2D location, int radius) : location(location), radius(radius)
{}

bool SphereCollider::HitSphere(SphereCollider* collider)
{
    // �~�Ɖ~�̓����蔻��
    // �������瑊��ւ̃x�N�g�������߂�
    Location2D location = this->GetLocation() - collider->GetLocation();

    // �x�N�g���̑傫�����擾�@��(x*x) + (y*y) 
    float vectorSize = location.GetLength();

    // �����̔��a�@�{�@����̔��a�@���擾
    float radius = static_cast<float>(this->radius + collider->GetRadius());

    // �x�N�g���̑傫���@�����@���v�̔��a�@�̎��������Ă�
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