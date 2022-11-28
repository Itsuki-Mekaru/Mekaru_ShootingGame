#include "CharaBase.h"

CharaBase::CharaBase(T_Location location, float radius, T_Location speed)
    : SphereCollider(location, radius), speed(speed), image(nullptr), bullets(nullptr)
{
}

BulletBase** CharaBase::GetBullets()
{
    return bullets;
}

void CharaBase::DeleteBullet(int bulletNum, int all)
{
    delete bullets[bulletNum];
    bullets[bulletNum] = nullptr;

    // ”z—ñ‚ð‘O‚É‹l‚ß‚é
    for(int i = bulletNum + 1; i < all; i++)
    {
        if(bullets[i] == nullptr)
        {
            break;
        }
        bullets[i - 1] = bullets[i];
        bullets[i] = nullptr;
    }
}