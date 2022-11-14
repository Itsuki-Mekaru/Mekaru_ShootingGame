#pragma once
#include "AbstractScene.h"
#include "Player.h"
#include "Enemy.h"
#include "ItemBase.h"

class GameMainScene : public AbstractScene
{
private:
    Player* player;
    Enemy** enemy;
    ItemBase** items;

public:
    GameMainScene()
    {
        Location2D location;
        location.x = 10.f;
        location.y = 100.f;

        int radius = 10;

        player = new Player(location, radius);

        enemy = new Enemy*[10];
        for(int i = 0; i < 10; i++)
        {
            enemy[i] = nullptr;
        }
        enemy[0] = new Enemy(Location2D{300.f, 0.f}, 20);

        items = new ItemBase*[10];
        for(int i = 0; i < 10; i++)
        {
            items[i] = nullptr;
        }
    }

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