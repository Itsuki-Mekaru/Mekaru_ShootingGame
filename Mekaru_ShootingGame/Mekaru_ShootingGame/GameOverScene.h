#pragma once
#include "AbstractScene.h"

class GameOverScene : public AbstractScene
{
public:
    // �f�X�g���N�^
    virtual ~GameOverScene()
    {};

    //�`��ȊO�̍X�V����������
    virtual AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const override;
};

