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

#ifdef _ON_INPUT_MOUSE_
int InputManager::oldMouseKey;  // 前回の入力マウスキー
int InputManager::nowMouseKey;  // 今回の入力マウスキー

void InputManager::MouseUpdate()
{
    oldMouseKey = nowMouseKey;
    nowMouseKey = GetMouseInput();
}
bool InputManager::MouseClick(int inputKey)
{
    int keyFlag = (nowMouseKey & ~oldMouseKey);
    bool ret = ((keyFlag & inputKey) != 0);
    return ret;
}
bool InputManager::MousePressed(int inputKey)
{
    bool ret = ((nowMouseKey & inputKey) != 0);
    return ret;
}
bool InputManager::MouseRelease(int inputKey)
{
    int keyFlag = (~nowMouseKey & oldMouseKey);
    bool ret = ((keyFlag & inputKey) != 0);
    return ret;
}
#endif // _ON_INPUT_MOUSE_

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

bool InputManager::KeyboardPressed(int inputKey)
{
    bool ret = (nowKeyboardKey[inputKey] == 1);
    return ret;
}

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
{
    oldKeyAndPad1Key = nowKeyAndPad1Key;
    nowKeyAndPad1Key = GetJoypadInputState(DX_INPUT_KEY_PAD1);
}
bool InputManager::KeyAndPad1Click(int inputKey)
{
    int keyFlag = (nowKeyAndPad1Key & ~oldKeyAndPad1Key);
    bool ret = ((keyFlag & inputKey) != 0);
    return ret;
}
bool InputManager::KeyAndPad1Pressed(int inputKey)
{
    bool ret = ((nowKeyAndPad1Key & inputKey) != 0);
    return ret;
}
bool InputManager::KeyAndPad1Release(int inputKey)
{
    int keyFlag = (~nowKeyAndPad1Key & oldKeyAndPad1Key);
    bool ret = ((keyFlag & inputKey) != 0);
    return ret;
}
#endif // _ON_INPUT_KEYBOARD_AND_JOYPAD1_

#ifdef _ON_INPUT_JOYPAD1_
int InputManager::oldPad1Key;
int InputManager::nowPad1Key;

bool InputManager::Pad1Update()
{
    oldPad1Key = nowPad1Key;
    nowPad1Key = GetJoypadInputState(DX_INPUT_PAD1);
}
bool InputManager::Pad1Click(int inputKey)
{
    int keyFlag = (nowPad1Key & ~oldPad1Key);
    bool ret = ((keyFlag & inputKey) != 0);
    return ret;
}
bool InputManager::Pad1Pressed(int inputKey)
{
    bool ret = ((nowPad1Key & inputKey) != 0);
    return ret;
}
bool InputManager::Pad1Release(int inputKey)
{
    int keyFlag = (~nowPad1Key & oldPad1Key);
    bool ret = ((keyFlag & inputKey) != 0);
    return ret;
}
#endif // _ON_INPUT_JOYPAD1_

#ifdef _ON_INPUT_JOYPAD2_
int InputManager::oldPad2Key;                  // 前回の入力コントローラー２キー
int InputManager::nowPad2Key;                  // 今回の入力コントローラー２キー

bool InputManager::Pad2Update()
{
    oldPad2Key = nowPad2Key;
    nowPad2Key = GetJoypadInputState(DX_INPUT_PAD2);
}
bool InputManager::Pad2Click(int inputKey)
{
    int keyFlag = (nowPad2Key & ~oldPad2Key);
    bool ret = ((keyFlag & inputKey) != 0);
    return ret;
}
bool InputManager::Pad2Pressed(int inputKey)
{
    bool ret = ((nowPad2Key & inputKey) != 0);
    return ret;
}
bool InputManager::Pad2Release(int inputKey)
{
    int keyFlag = (~nowPad2Key & oldPad2Key);
    bool ret = ((keyFlag & inputKey) != 0);
    return ret;
}
#endif // _ON_INPUT_JOYPAD2_

#ifdef _ON_INPUT_JOYPAD3_
int InputManager::oldPad3Key;                  // 前回の入力コントローラー３キー
int InputManager::nowPad3Key;                  // 今回の入力コントローラー３キー

bool InputManager::Pad3Update()
{
    oldPad3Key = nowPad3Key;
    nowPad3Key = GetJoypadInputState(DX_INPUT_PAD3);
}
bool InputManager::Pad3Click(int inputKey)
{
    int keyFlag = (nowPad3Key & ~oldPad3Key);
    bool ret = ((keyFlag & inputKey) != 0);
    return ret;
}
bool InputManager::Pad3Pressed(int inputKey)
{
    bool ret = ((nowPad3Key & inputKey) != 0);
    return ret;
}
bool InputManager::Pad3Release(int inputKey)
{
    int keyFlag = (~nowPad3Key & oldPad3Key);
    bool ret = ((keyFlag & inputKey) != 0);
    return ret;
}
#endif // _ON_INPUT_JOYPAD3_

#ifdef _ON_INPUT_JOYPAD4_
int InputManager::oldPad4Key;                  // 前回の入力コントローラー４キー
int InputManager::nowPad4Key;                  // 今回の入力コントローラー４キー

bool InputManager::Pad4Update()
{
    oldPad4Key = nowPad4Key;
    nowPad4Key = GetJoypadInputState(DX_INPUT_PAD4);
}
bool InputManager::Pad4Click(int inputKey)
{
    int keyFlag = (nowPad4Key & ~oldPad4Key);
    bool ret = ((keyFlag & inputKey) != 0);
    return ret;
}
bool InputManager::Pad4Pressed(int inputKey)
{
    bool ret = ((nowPad4Key & inputKey) != 0);
    return ret;
}
bool InputManager::Pad4Release(int inputKey)
{
    int keyFlag = (~nowPad4Key & oldPad4Key);
    bool ret = ((keyFlag & inputKey) != 0);
    return ret;
}
#endif // _ON_INPUT_JOYPAD4_

#ifdef _ON_INPUT_PAD_KEYBOARD_
int InputManager::oldPadKeyboardKey;                   // 前回の入力パッドキーボードキー
int InputManager::nowPadKeyboardKey;                   // 今回の入力パッドキーボードキー

bool InputManager::PadKeyboardUpdate()
{
    oldPadKeyboardKey = nowPadKeyboardKey;
    nowPadKeyboardKey = GetJoypadInputState(DX_INPUT_KEY);
}
bool InputManager::PadKeyboardClick(int inputKey)
{
    int keyFlag = (nowPadKeyboardKey & ~oldPadKeyboardKey);
    bool ret = ((keyFlag & inputKey) != 0);
    return ret;
}
bool InputManager::PadKeyboardPressed(int inputKey)
{
    bool ret = ((nowPadKeyboardKey & inputKey) != 0);
    return ret;
}
bool InputManager::PadKeyboardRelease(int inputKey)
{
    int keyFlag = (~nowPadKeyboardKey & oldPadKeyboardKey);
    bool ret = ((keyFlag & inputKey) != 0);
    return ret;
}
#endif // _ON_INPUT_PAD_KEYBOARD_