#pragma once

#define _ON_INPUT_KEYBOARD_
#define _ON_INPUT_KEYBOARD_AND_JOYPAD1_
#define _ON_INPUT_JOYPAD1_
#define _ON_INPUT_JOYPAD2_
#define _ON_INPUT_JOYPAD3_
#define _ON_INPUT_JOYPAD4_
#define _ON_INPUT_PAD_KEYBOARD_

class InputManager
{
private:
    InputManager() = default;

public:
    static void Update();   // 全てのキーの
    static bool PadClick(int DxInputKeyOrPad, int inputKey);    // ボタンを押した瞬間
    static bool PadPressed(int DxInputKeyOrPad, int inputKey);  // ボタンを押している間
    static bool PadRelease(int DxInputKeyOrPad, int inputKey);  // ボタンを離した瞬間

#ifdef _ON_INPUT_KEYBOARD_
private:
    static char oldKeyboardKey[256];            // 前回の入力キーボードキー
    static char nowKeyboardKey[256];            // 今回の入力キーボードキー
public:
    static bool KeyboardUpdate();               // キーの更新
    static bool KeyboardClick(int inputKey);    // ボタンを押した瞬間
    static bool KeyboardPressed(int inputKey);  // ボタンを押している間
    static bool KeyboardRelease(int inputKey);  // ボタンを離した瞬間
#endif // _ON_INPUT_KEYBOARD_

#ifdef _ON_INPUT_KEYBOARD_AND_JOYPAD1_
private:
    static int oldKeyAndPad1Key;                    // 前回の入力キーボード&コントローラー１キー
    static int nowKeyAndPad1Key;                    // 今回の入力キーボード&コントローラー１キー
public:
    static bool KeyAndPad1Update();               // キーの更新
    static bool KeyAndPad1Click(int inputKey);      // ボタンを押した瞬間
    static bool KeyAndPad1Pressed(int inputKey);    // ボタンを押している間
    static bool KeyAndPad1Release(int inputKey);    // ボタンを離した瞬間
#endif // _ON_INPUT_KEYBOARD_AND_JOYPAD1_

#ifdef _ON_INPUT_JOYPAD1_
private:
    static int oldPad1Key;                  // 前回の入力コントローラー１キー
    static int nowPad1Key;                  // 今回の入力コントローラー１キー
public:
    static bool Pad1Update();               // キーの更新
    static bool Pad1Click(int inputKey);    // ボタンを押した瞬間
    static bool Pad1Pressed(int inputKey);  // ボタンを押している間
    static bool Pad1Release(int inputKey);  // ボタンを離した瞬間
#endif // _ON_INPUT_JOYPAD1_

#ifdef _ON_INPUT_JOYPAD2_
private:
    static int oldPad2Key;                  // 前回の入力コントローラー２キー
    static int nowPad2Key;                  // 今回の入力コントローラー２キー
public:
    static bool Pad2Update();               // キーの更新
    static bool Pad2Click(int inputKey);    // ボタンを押した瞬間
    static bool Pad2Pressed(int inputKey);  // ボタンを押している間
    static bool Pad2Release(int inputKey);  // ボタンを離した瞬間
#endif // _ON_INPUT_JOYPAD2_

#ifdef _ON_INPUT_JOYPAD3_
private:
    static int oldPad3Key;                  // 前回の入力コントローラー３キー
    static int nowPad3Key;                  // 今回の入力コントローラー３キー
public:
    static bool Pad3Update();               // キーの更新
    static bool Pad3Click(int inputKey);    // ボタンを押した瞬間
    static bool Pad3Pressed(int inputKey);  // ボタンを押している間
    static bool Pad3Release(int inputKey);  // ボタンを離した瞬間
#endif // _ON_INPUT_JOYPAD3_

#ifdef _ON_INPUT_JOYPAD4_
private:
    static int oldPad4Key;                  // 前回の入力コントローラー４キー
    static int nowPad4Key;                  // 今回の入力コントローラー４キー
public:
    static bool Pad4Update();               // キーの更新
    static bool Pad4Click(int inputKey);    // ボタンを押した瞬間
    static bool Pad4Pressed(int inputKey);  // ボタンを押している間
    static bool Pad4Release(int inputKey);  // ボタンを離した瞬間
#endif // _ON_INPUT_JOYPAD4_

#ifdef _ON_INPUT_PAD_KEYBOARD_
private:
    static int oldPadKeyboardKey;                   // 前回の入力パッドキーボードキー
    static int nowPadKeyboardKey;                   // 今回の入力パッドキーボードキー
public:
    static bool PadKeyboardUpdate();               // キーの更新
    static bool PadKeyboardClick(int inputKey);     // ボタンを押した瞬間
    static bool PadKeyboardPressed(int inputKey);   // ボタンを押している間
    static bool PadKeyboardRelease(int inputKey);   // ボタンを離した瞬間
#endif // _ON_INPUT_PAD_KEYBOARD_
};

