#include "DxLib.h"
#include "Enemy.h"
#include "StraightBullets.h"
#include "CircleBullet.h"

#define ATTACK_INTERVAL 5

void Enemy::inputCSV()
{
    FILE *fp;   // FILE型構造体
    errno_t error;
    error = fopen_s(&fp, "../data/T_MoveInformation.csv", "r");

    if(error != 0)
    {
        // ファイルが開けてない
        return;
    }
    else
    {
        // ファイルが開けた
        char line[100];
        for(int i = 0; fgets(line, 100, fp) != NULL; i++)
        {
            sscanf_s(line, "%d, %f, %f, %d, %d, %d",
                   &moveInfo[i].pattern,
                   &moveInfo[i].destination.x,
                   &moveInfo[i].destination.y,
                   &moveInfo[i].nextArrayNum,
                   &moveInfo[i].waitFrameTime,
                   &moveInfo[i].attackType
            );
        }
    }

    fclose(fp); // ファイルを閉じる
}


Enemy::Enemy(T_Location location, float radius)
    : SphereCollider(location, radius)
{

    inputCSV();

    hp = 10;
    point = 10;
    WaitCount = 99;
    shotNum = 0;

    speed = T_Location{ 1, 1 };

    bullets = new BulletsBase * [30];
    for(int i = 0; i < 30; i++)
    {
        bullets[i] = nullptr;
    }
}

void Enemy::Update()
{
    //T_Location newLocation = GetLocation();
    //newLocation.y += speed.y;
    //SetLocation(newLocation);

    switch(moveInfo[current].pattern)
    {
        case 0:
            Move();
            break;

        case 1:
            waitTime++;
            if(moveInfo[current].waitFrameTime <= waitTime)
            {
                waitTime = 0;
                current = moveInfo[current].nextArrayNum;
            }
            break;

        default:
            break;
    }

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
            DeleteBullet(bulletCount);
            bulletCount--;
        }
    }

    if(moveInfo[current].attackType != 0)
    {
        WaitCount++;
        if(ATTACK_INTERVAL <= WaitCount)
        {
            if(bulletCount < 30 && bullets[bulletCount] == nullptr)
            {
                WaitCount = 0;
                if(moveInfo[current].attackType == 1)
                {
                    bullets[bulletCount] = new StraightBullets(GetLocation(), T_Location{ 0, 2 });
                }
                else if(moveInfo[current].attackType == 2){
                    shotNum++;
                    bullets[bulletCount] = new CircleBullet(GetLocation(), 2.f, (20 * shotNum));
                }
            }
        }
    }
}

void Enemy::Draw()
{
    DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 0, 255));

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

void Enemy::Hit()
{

}

void Enemy::Hit(int damage)
{
    if(0 < damage)
    {
        hp -= damage;
        if(hp < 0)
        {
            hp = 0;
        }
    }
}

bool Enemy::HpCheck()
{
    bool ret = (hp <= 0);
    return ret;
}

int Enemy::GetPoint()
{
    return point;
}

void Enemy::DeleteBullet(int bulletCount)
{
    delete bullets[bulletCount];
    bullets[bulletCount] = nullptr;

    for(int i = (bulletCount + 1); i < 30; i++)
    {
        if(bullets[i] == nullptr)
        {
            break;
        }
        bullets[i - 1] = bullets[i];
        bullets[i] = nullptr;
    }
}

void Enemy::Move()
{
    T_Location newLocation = GetLocation();

    if((newLocation.x == moveInfo[current].destination.x) &&
       (newLocation.y == moveInfo[current].destination.y))
    {
        current = moveInfo[current].nextArrayNum;
        return;
    }
    else
    {
        if(newLocation.x != moveInfo[current].destination.x)
        {
            if(newLocation.x < moveInfo[current].destination.x)
            {
                newLocation.x += speed.x;
                if(moveInfo[current].destination.x < newLocation.x)
                {
                    newLocation.x = moveInfo[current].destination.x;
                }
            }
            else
            {
                newLocation.x -= speed.x;
                if(newLocation.x < moveInfo[current].destination.x)
                {
                    newLocation.x = moveInfo[current].destination.x;
                }
            }
        }

        if(newLocation.y != moveInfo[current].destination.y)
        {
            if(newLocation.y < moveInfo[current].destination.y)
            {
                newLocation.y += speed.y;
                if(moveInfo[current].destination.y < newLocation.y)
                {
                    newLocation.y = moveInfo[current].destination.y;
                }
            }
            else
            {
                newLocation.y -= speed.y;
                if(newLocation.y < moveInfo[current].destination.y)
                {
                    newLocation.y = moveInfo[current].destination.y;
                }
            }
        }
    }

    SetLocation(newLocation);
}