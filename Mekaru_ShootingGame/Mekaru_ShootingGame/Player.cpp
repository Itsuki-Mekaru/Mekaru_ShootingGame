#include <math.h>
#include "DxLib.h"
#include "Player.h"
#include "Input.h"
#include "StraightBullets.h"

Location2D getNewLocation(Location2D newLocation);

Player::Player(Location2D location, int radius)
    : CharaBase(location, radius), score(0), life(10)
{
    // imageÇÃèâä˙âª
    // speedÇÃèâä˙âª

    bullets = new BulletsBase * [30];
    for(int i = 0; i < 30; i++)
    {
        bullets[i] = nullptr;
    }
}

void Player::Update()
{
    Location2D newLocation = getNewLocation(GetLocation());
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

    if(InputManager::KeyboardClick(KEY_INPUT_P))
    {
        if(bulletCount < 30 && bullets[bulletCount] == nullptr)
        {
            bullets[bulletCount] = new StraightBullets(GetLocation());
        }
    }
}

void Player::Draw()
{
    DrawCircle(static_cast<int>(floorf(GetLocation().x)), static_cast<int>(floorf(GetLocation().y)), GetRadius(), GetColor(255, 0, 0));

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

void Player::Hit(int bulletsCount)
{
    delete bullets[bulletsCount];
    bullets[bulletsCount] = nullptr;

    for(int i = (bulletsCount + 1); i < 30; i++)
    {
        if(bullets[i] == nullptr)
        {
            break;
        }
        bullets[i - 1] = bullets[i];
        bullets[i] = nullptr;
    }
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

void Player::addScore(int point)
{
    if(0 < point)
    {
        score += point;
    }
}

Location2D getNewLocation(Location2D newLocation)
{
    if(InputManager::KeyboardPressed(KEY_INPUT_W))
    {
        newLocation.y -= 2;
    }

    if(InputManager::KeyboardPressed(KEY_INPUT_A))
    {
        newLocation.x -= 2;
    }

    if(InputManager::KeyboardPressed(KEY_INPUT_S))
    {
        newLocation.y += 2;
    }

    if(InputManager::KeyboardPressed(KEY_INPUT_D))
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
