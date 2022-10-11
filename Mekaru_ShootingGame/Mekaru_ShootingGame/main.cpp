#include "DxLib.h"
#include "SceneManager.h"
#include "GameMainScene.h"

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    SetMainWindowText("�V���[�e�B���O�Q�[��");    // �^�C�g���� �V���[�e�B���O�Q�[�� �ɕύX

    ChangeWindowMode(TRUE); // �E�B���h�E���[�h�ŋN��

    if(DxLib_Init() == -1)  // DX���C�u�����̏���������
    {
        return -1;	
    }

    SetDrawScreen(DX_SCREEN_BACK);  // �`����ʂ𗠂ɂ���

    SetFontSize(20);    // �����T�C�Y��ݒ�

    // �V�[���}�l�[�W���I�u�W�F�N�g�̍쐬
    SceneManager sceneMng(dynamic_cast<AbstractScene*>(new GameMainScene()));

    // �Q�[�����[�v
    while(ProcessMessage() == 0)
    {
        ClearDrawScreen();  // ��ʂ̏�����

        sceneMng.Update();  // �V�[���̍X�V����
        sceneMng.Draw();    // �V�[���̕`�揈��
        if(sceneMng.ChangeScene() == nullptr)   // �V�[���̕ύX����
        {
            DxLib_End();    // DX���C�u�����g�p�̏I������
            return 0;   // �\�t�g�̏I��
        }

        ScreenFlip();   // ����ʂ̓��e��\��ʂɔ��f
    }

    DxLib_End();    // DX���C�u�����g�p�̏I������
    return 0;   // �\�t�g�̏I��
}