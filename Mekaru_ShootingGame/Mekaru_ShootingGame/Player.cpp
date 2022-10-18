#include "DxLib.h"
#include "Player.h"
#include "KeyManager.h"
#include "StraightBullets.h"

T_Location getNewLocation(T_Location newLocation);

Player::Player(T_Location location, float radius) 
    : SphereCollider(location, radius)
{
    score = 0;  // Œ»İƒXƒRƒA
    life = 10;  // HP
    // image‚Ì‰Šú‰»
    // speed‚Ì‰Šú‰»

    bullets = new BulletsBase*[30];
    for(int i = 0; i < 30; i++)
    {
        bullets[i] = nullptr;
    }
}

void Player::Update()
{
    T_Location newLocation = getNewLocation(GetLocation());
    SetLocation(newLocation);

    int bulletCount;
    for(bulletCount = 0; bulletCount < 30; bulletCount++)
    {
        if(bullets[bulletCount] == nullptr)
        {
            break;
        }
        bullets[bulletCount]->Update();
    }

    if(KeyManager::OnClick(KEY_INPUT_P))
    {
        int i;
        for(i = 0; i < 30; i++)
        {
            if(bullets[i] == nullptr)
            {
                break;
            }
        }
        bullets[i] = new StraightBullets(GetLocation());
    }
}

void Player::Draw()
{
    DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 0));

    int bulletCount;
    for(bulletCount = 0; bulletCount < 30; bulletCount++)
    {
        if(bullets[bulletCount] == nullptr)
        {
            break;
        }
        bullets[bulletCount]->Draw();
    }
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

T_Location getNewLocation(T_Location newLocation)
{
    if(KeyManager::OnPressed(KEY_INPUT_W))
    {
        newLocation.y -= 2;
    }
    if(KeyManager::OnPressed(KEY_INPUT_A))
    {
        newLocation.x -= 2;
    }
    if(KeyManager::OnPressed(KEY_INPUT_S))
    {
        newLocation.y += 2;
    }
    if(KeyManager::OnPressed(KEY_INPUT_D))
    {
        newLocation.x += 2;
    }
    return newLocation;
}