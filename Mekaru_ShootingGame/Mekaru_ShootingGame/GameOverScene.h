#pragma once
#include "AbstractScene.h"

class GameOverScene : public AbstractScene
{
public:
    // �f�X�g���N�^
    virtual ~GameOverScene()
    {};

    //�`��ȊO�̍X�V����������
    virtual void Update() override;

    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const override;

    AbstractScene* ChangeScene() override;
};

