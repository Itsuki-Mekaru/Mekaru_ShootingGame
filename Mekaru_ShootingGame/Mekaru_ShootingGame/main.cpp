/********************************************************************
**	��S�́@�Q�[���v���O���~���O�̊�{
**	�@�u���b�N�����Q�[���̍쐬(2018)
********************************************************************/
#include "DxLib.h"
#include "common.h"
#include "SceneManager.h"
#include "TitleScene.h"

/***********************************************
 * �v���O�����̊J�n
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    SetMainWindowText("�V���[�e�B���O�Q�[��");    // �^�C�g����ݒ�

    ChangeWindowMode(TRUE);		// �E�B���h�E���[�h�ŋN��

    SetWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
    SetGraphMode(SCREEN_WIDTH, SCREEN_HEIGHT, SCREEN_COLOR_BIT_16);

    if(DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������

    SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���

    SetFontSize(20);		// �����T�C�Y��ݒ�

    SceneManager sceneMng(dynamic_cast<AbstractScene*>(new TitleScene()));

    // �Q�[�����[�v
    while(ProcessMessage() == 0 && sceneMng.Update() != nullptr)
    {
        ClearDrawScreen();		// ��ʂ̏�����
        sceneMng.Draw();
        ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f
    }

    DxLib_End();	// DX���C�u�����g�p�̏I������

    return 0;	// �\�t�g�̏I��
}