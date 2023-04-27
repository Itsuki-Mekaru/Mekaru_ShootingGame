#pragma once
#include "StraightBullets.h"

#define PLAYER_BULLET_MAX (100)
class BulletManager
{
// シングルトン
private:
    BulletManager()
    {
        pBullets = new BulletsBase*[PLAYER_BULLET_MAX];
        eBullets = nullptr;
        pCount = 0;
        eCount = 0;
        eBulletMax = -1;
    }
    static BulletManager* instance;

public:
    static BulletManager* GetInstance()
    {
        if(instance == nullptr)
        {
            instance = new BulletManager();
        }

        return instance;
    }
// シングルトン　ここまで

private:
    class BulletsBase** pBullets;
    class BulletsBase** eBullets;
    int pCount;
    int eCount;
    int eBulletMax;

public:
    virtual ~BulletManager()
    {
    }

    void CreatePlayerBullet(/*なんか*/)
    {
        if(pCount < PLAYER_BULLET_MAX)
        {
            /*弾を生成*/
        }
    }

    void CreateEnemyBullet(/*なんか*/)
    {
        if(eBulletMax == pCount)
        {
            eBulletMax += 10;
            BulletsBase** temp = new BulletsBase*[eBulletMax];

            /*tempに移し替えて、eBullets削除*/
            
            eBullets = temp;
        }
        /*弾を生成*/
    }
    void CreateEnemyBullet(int i)
    {
        if(eBulletMax == pCount)
        {
            eBulletMax += 10;
            BulletsBase** temp = new BulletsBase * [eBulletMax];

            /*tempに移し替えて、eBullets削除*/

            eBullets = temp;
        }
        /*弾を生成*/
    }

    void CreateEnemyBullet(StraightBullets* a)
    {
        if(eBulletMax == pCount)
        {
            eBulletMax += 10;
            BulletsBase** temp = new BulletsBase * [eBulletMax];

            /*tempに移し替えて、eBullets削除*/

            eBullets = temp;
        }
        /*弾を生成*/
        eBullets[pCount] = dynamic_cast<BulletsBase*>(a);
    }

    BulletsBase** GetPlayerBullets()
    {
        return pBullets;
    }

    BulletsBase** DeletePlayerBullet(BulletsBase* b)
    {
        for(int i = 0; i < PLAYER_BULLET_MAX; i++)
        {
            if(pBullets[i] == b)
            {
                delete pBullets[i];
                /*弾を消す*/
            }
        }
    }
};

