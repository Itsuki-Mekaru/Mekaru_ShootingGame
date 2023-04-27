#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
#include "ItemBase.h"
#include "common.h"



class GameMainScene : public AbstractScene
{
private:
    Player* player;
    Enemy** enemy;
    ItemBase** items;

    class BulletManager* bMng;

    int waittime = 0;

    bool playerDeath = false;
    bool enemyDeath = false;

public:
    GameMainScene();

    // デストラクタ
    virtual ~GameMainScene() 
    {
        delete player;
    };

    //描画以外の更新を実装する
    virtual AbstractScene* Update() override;

    //描画に関することを実装する
    virtual void Draw() const override;
};