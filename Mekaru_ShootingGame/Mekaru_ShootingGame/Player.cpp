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

    bullets = new BulletsBase * [30];
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

        if(bullets[bulletCount]->isDeath())
        {
            delete bullets[bulletCount];
            bullets[bulletCount] = nullptr;

            for(int i = (bulletCount + 1); i < 30; i++)
            {
                if(bullets[i] == nullptr)
                {
                    break;
                }
                bullets[i -1] = bullets[i];
                bullets[i] = nullptr;
            }
            bulletCount--;
        }
    }

    if(KeyManager::OnClick(KEY_INPUT_P))
    {
        if(bulletCount < 30 && bullets[bulletCount] == nullptr)
        {
            bullets[bulletCount] = new StraightBullets(GetLocation());
        }
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
{}

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




void bubbleSort(int array[], int array_size)
{
    int i, j, k;

    for(i = 0; i < (array_size - 1); i++)
    {
        if(array[i + 1] < array[i])
        {
            k = array[i];
            array[i] = array[i + 1];
            array[i + 1] = k;
        }
    }
}















//
//bullets[bulletCount] = nullptr;
//
//for(int i = bulletCount; i < 29; i++)
//{
//    if(bullets[i + 1] == nullptr)
//    {
//        break;
//    }
//    bullets[i] = bullets[i + 1];
//    bullets[i + 1] = nullptr;
//}
//bulletCount--;