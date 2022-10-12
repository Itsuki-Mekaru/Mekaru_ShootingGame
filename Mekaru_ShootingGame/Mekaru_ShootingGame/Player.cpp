#include "DxLib.h"
#include "Player.h"

Player::Player(T_Location location, float radius) 
    : SphereCollider(location, radius)
{
    score = 0;  // Œ»İƒXƒRƒA
    life = 10;   // HP
    // image‚Ì‰Šú‰»
    // speed‚Ì‰Šú‰»
}

void Player::Update()
{
    T_Location l;
    l.x = GetLocation().x + 0.1f;
    l.y = GetLocation().y;
    SetLocation(l);
}

void Player::Draw()
{
    DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(0, 0, 255));
}

void Player::Hit()
{
}

bool Player::LifeCheck()
{
    bool ret = (life <= 0);
    return ret;
}

int Player::GetScore()
{
    return score;
}