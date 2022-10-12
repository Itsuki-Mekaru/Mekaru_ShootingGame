/********************************************************************
**	第４章　ゲームプログラミングの基本
**	　ブロック崩しゲームの作成(2018)
********************************************************************/
#include "DxLib.h"
#include "SceneManager.h"
#include "GameMainScene.h"

/***********************************************
 * プログラムの開始
 ***********************************************/
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
    SetMainWindowText("シューティングゲーム");    // タイトルを設定

    ChangeWindowMode(TRUE);		// ウィンドウモードで起動

    if(DxLib_Init() == -1) return -1;	// DXライブラリの初期化処理

    SetDrawScreen(DX_SCREEN_BACK);	// 描画先画面を裏にする

    SetFontSize(20);		// 文字サイズを設定

    SceneManager sceneMng((AbstractScene*)new GameMainScene());

    // ゲームループ
    while(ProcessMessage() == 0 && sceneMng.Update() != nullptr)
    {
        ClearDrawScreen();		// 画面の初期化
        sceneMng.Draw();
        ScreenFlip();			// 裏画面の内容を表画面に反映
    }

    DxLib_End();	// DXライブラリ使用の終了処理

    return 0;	// ソフトの終了
}