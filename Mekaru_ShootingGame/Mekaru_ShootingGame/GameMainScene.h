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

    // �f�X�g���N�^
    virtual ~GameMainScene() 
    {
        delete player;
    };

    //�`��ȊO�̍X�V����������
    virtual AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const override;
};