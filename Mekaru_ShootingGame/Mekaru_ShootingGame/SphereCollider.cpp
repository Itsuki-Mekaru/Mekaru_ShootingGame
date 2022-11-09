#include "SphereCollider.h"
#include <math.h>

SphereCollider::SphereCollider(Location2D location, float radius)
{
    this->location = location;
    this->radius = radius;
}

bool SphereCollider::HitSphere(SphereCollider* collider)
{
    // �~�Ɖ~�̓����蔻��
    // �������瑊��ւ̃x�N�g�������߂�
    Location2D a = collider->GetLocation();
    Location2D location = this->GetLocation() - collider->GetLocation();

    // ��Βl�ɕϊ�
    x = fabsf(x);
    y = fabsf(y);

    // �x�N�g���̑傫�����擾�@��(x*x) + (y*y) 
    float xy = (x * x) + (y * y);
    double vectorSize = sqrt(xy);

    // �����̔��a�@�{�@����̔��a�@���擾
    float radius = this->radius + s->GetRadius();

    // �x�N�g���̑傫���@�����@���v�̔��a�@�̎��������Ă�
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