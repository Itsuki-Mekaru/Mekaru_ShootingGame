#pragma once
#include "AbstractScene.h"

class TitleScene : public AbstractScene
{
public:
    TitleScene();

    // �f�X�g���N�^
    virtual ~TitleScene()
    {};

    //�`��ȊO�̍X�V����������
    virtual AbstractScene* Update() override;

    //�`��Ɋւ��邱�Ƃ���������
    virtual void Draw() const override;
};

