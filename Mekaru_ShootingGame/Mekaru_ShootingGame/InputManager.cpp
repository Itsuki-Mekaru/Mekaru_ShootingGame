#include "InputManager.h"
#include "DxLib.h"

void InputManager::Update()
{
#ifdef _ON_INPUT_KEYBOARD_
    KeyboardUpdate();
#endif // _ON_INPUT_KEYBOARD_
#ifdef _ON_INPUT_KEYBOARD_AND_JOYPAD1_
    KeyAndPad1Update();
#endif // _ON_INPUT_KEYBOARD_AND_JOYPAD1_

#ifdef _ON_INPUT_JOYPAD1_
    Pad1Update();
#endif // _ON_INPUT_JOYPAD1_

#ifdef _ON_INPUT_JOYPAD2_
    Pad2Update();
#endif // _ON_INPUT_JOYPAD2_

#ifdef _ON_INPUT_JOYPAD3_
    Pad3Update();
#endif // _ON_INPUT_JOYPAD3_

#ifdef _ON_INPUT_JOYPAD4_
    Pad4Update();
#endif // _ON_INPUT_JOYPAD4_

#ifdef _ON_INPUT_PAD_KEYBOARD_
    PadKeyboardUpdate();
#endif // _ON_INPUT_PAD_KEYBOARD_



    //oldJoypadKey = nowJoypadKey;
    //nowJoypadKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
}

bool InputManager::PadClick(int DxInputKeyOrPad, int inputKey)
{
    switch(DxInputKeyOrPad)
    {
#ifdef _ON_INPUT_KEYBOARD_AND_JOYPAD1_
        case DX_INPUT_KEY_PAD1:
            return KeyAndPad1Click(inputKey);
#endif // _ON_INPUT_KEYBOARD_AND_JOYPAD1_

#ifdef _ON_INPUT_JOYPAD1_
        case DX_INPUT_PAD1:
            return Pad1Click(inputKey);
#endif // _ON_INPUT_JOYPAD1_

#ifdef _ON_INPUT_JOYPAD2_
        case DX_INPUT_PAD2:
            return Pad2Click(inputKey);
#endif // _ON_INPUT_JOYPAD2_

#ifdef _ON_INPUT_JOYPAD3_
        case DX_INPUT_PAD3:
            return Pad3Click(inputKey);
#endif // _ON_INPUT_JOYPAD3_

#ifdef _ON_INPUT_JOYPAD4_
        case DX_INPUT_PAD4:
            return Pad4Click(inputKey);
#endif // _ON_INPUT_JOYPAD4_

#ifdef _ON_INPUT_PAD_KEYBOARD_
        case DX_INPUT_KEY:
            return PadKeyboardClick(inputKey);
#endif // _ON_INPUT_PAD_KEYBOARD_

        default:
            return false;

    }
}

bool InputManager::PadPressed(int DxInputKeyOrPad, int inputKey)
{
    switch(DxInputKeyOrPad)
    {
#ifdef _ON_INPUT_KEYBOARD_AND_JOYPAD1_
        case DX_INPUT_KEY_PAD1:
            return KeyAndPad1Pressed(inputKey);
#endif // _ON_INPUT_KEYBOARD_AND_JOYPAD1_

#ifdef _ON_INPUT_JOYPAD1_
        case DX_INPUT_PAD1:
            return Pad1Pressed(inputKey);
#endif // _ON_INPUT_JOYPAD1_

#ifdef _ON_INPUT_JOYPAD2_
        case DX_INPUT_PAD2:
            return Pad2Pressed(inputKey);
#endif // _ON_INPUT_JOYPAD2_

#ifdef _ON_INPUT_JOYPAD3_
        case DX_INPUT_PAD3:
            return Pad3Pressed(inputKey);
#endif // _ON_INPUT_JOYPAD3_

#ifdef _ON_INPUT_JOYPAD4_
        case DX_INPUT_PAD4:
            return Pad4Pressed(inputKey);
#endif // _ON_INPUT_JOYPAD4_

#ifdef _ON_INPUT_PAD_KEYBOARD_
        case DX_INPUT_KEY:
            return PadKeyboardPressed(inputKey);
#endif // _ON_INPUT_PAD_KEYBOARD_

        default:
            return false;

    }
}

bool InputManager::PadRelease(int DxInputKeyOrPad, int inputKey)
{
    switch(DxInputKeyOrPad)
    {
#ifdef _ON_INPUT_KEYBOARD_AND_JOYPAD1_
        case DX_INPUT_KEY_PAD1:
            return KeyAndPad1Release(inputKey);
#endif // _ON_INPUT_KEYBOARD_AND_JOYPAD1_

#ifdef _ON_INPUT_JOYPAD1_
        case DX_INPUT_PAD1:
            return Pad1Release(inputKey);
#endif // _ON_INPUT_JOYPAD1_

#ifdef _ON_INPUT_JOYPAD2_
        case DX_INPUT_PAD2:
            return Pad2Release(inputKey);
#endif // _ON_INPUT_JOYPAD2_

#ifdef _ON_INPUT_JOYPAD3_
        case DX_INPUT_PAD3:
            return Pad3Release(inputKey);
#endif // _ON_INPUT_JOYPAD3_

#ifdef _ON_INPUT_JOYPAD4_
        case DX_INPUT_PAD4:
            return Pad4Release(inputKey);
#endif // _ON_INPUT_JOYPAD4_

#ifdef _ON_INPUT_PAD_KEYBOARD_
        case DX_INPUT_KEY:
            return PadKeyboardRelease(inputKey);
#endif // _ON_INPUT_PAD_KEYBOARD_

        default:
            return false;

    }
}

#ifdef _ON_INPUT_KEYBOARD_
char InputManager::oldKeyboardKey[256];
char InputManager::nowKeyboardKey[256];

bool InputManager::KeyboardUpdate()
{
    for(int i = 0; i < 256; i++)
    {
        oldKeyboardKey[i] = nowKeyboardKey[i];
    }
    bool ret = GetHitKeyStateAll(nowKeyboardKey);
    return ret;
}

bool InputManager::KeyboardClick(int inputKey)
{
    bool ret = (nowKeyboardKey[inputKey] == 1 && oldKeyboardKey[inputKey] == 0);
    return ret;
}

// ボタンを押している間
bool InputManager::KeyboardPressed(int inputKey)
{
    bool ret = (nowKeyboardKey[inputKey] == 1);
    return ret;
}

// ボタンを離した瞬間
bool InputManager::KeyboardRelease(int inputKey)
{
    bool ret = (oldKeyboardKey[inputKey] == 1 && nowKeyboardKey[inputKey] == 0);
    return ret;
}
#endif // _ON_INPUT_KEYBOARD_

#ifdef _ON_INPUT_KEYBOARD_AND_JOYPAD1_
int InputManager::oldKeyAndPad1Key;
int InputManager::nowKeyAndPad1Key;

bool InputManager::KeyAndPad1Update()
{}
bool InputManager::KeyAndPad1Click(int inputKey)
{}
bool InputManager::KeyAndPad1Pressed(int inputKey)
{}
bool InputManager::KeyAndPad1Release(int inputKey)
{}
#endif // _ON_INPUT_KEYBOARD_AND_JOYPAD1_

#ifdef _ON_INPUT_JOYPAD1_
int InputManager::oldPad1Key;
int InputManager::nowPad1Key;

bool InputManager::Pad1Update()
{}
bool InputManager::Pad1Click(int inputKey)
{}
bool InputManager::Pad1Pressed(int inputKey)
{}
bool InputManager::Pad1Release(int inputKey)
{}
#endif // _ON_INPUT_JOYPAD1_

#ifdef _ON_INPUT_JOYPAD2_
int InputManager::oldPad2Key;                  // 前回の入力コントローラー２キー
int InputManager::nowPad2Key;                  // 今回の入力コントローラー２キー

bool InputManager::Pad2Update()
{}
bool InputManager::Pad2Click(int inputKey)
{}
bool InputManager::Pad2Pressed(int inputKey)
{}
bool InputManager::Pad2Release(int inputKey)
{}
#endif // _ON_INPUT_JOYPAD2_

#ifdef _ON_INPUT_JOYPAD3_
int InputManager::oldPad3Key;                  // 前回の入力コントローラー３キー
int InputManager::nowPad3Key;                  // 今回の入力コントローラー３キー

bool InputManager::Pad3Update()
{}
bool InputManager::Pad3Click(int inputKey)
{}
bool InputManager::Pad3Pressed(int inputKey)
{}
bool InputManager::Pad3Release(int inputKey)
{}
#endif // _ON_INPUT_JOYPAD3_

#ifdef _ON_INPUT_JOYPAD4_
int InputManager::oldPad4Key;                  // 前回の入力コントローラー４キー
int InputManager::nowPad4Key;                  // 今回の入力コントローラー４キー

bool InputManager::Pad4Update()
{}
bool InputManager::Pad4Click(int inputKey)
{}
bool InputManager::Pad4Pressed(int inputKey)
{}
bool InputManager::Pad4Release(int inputKey)
{}
#endif // _ON_INPUT_JOYPAD4_

#ifdef _ON_INPUT_PAD_KEYBOARD_
int InputManager::oldPadKeyboardKey;                   // 前回の入力パッドキーボードキー
int InputManager::nowPadKeyboardKey;                   // 今回の入力パッドキーボードキー

bool InputManager::PadKeyboardUpdate()
{}
bool InputManager::PadKeyboardClick(int inputKey)
{}
bool InputManager::PadKeyboardPressed(int inputKey)
{}
bool InputManager::PadKeyboardRelease(int inputKey)
{}
#endif // _ON_INPUT_PAD_KEYBOARD_