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
    static void Update();   // �S�ẴL�[��
    static bool PadClick(int DxInputKeyOrPad, int inputKey);    // �{�^�����������u��
    static bool PadPressed(int DxInputKeyOrPad, int inputKey);  // �{�^���������Ă����
    static bool PadRelease(int DxInputKeyOrPad, int inputKey);  // �{�^���𗣂����u��

#ifdef _ON_INPUT_KEYBOARD_
private:
    static char oldKeyboardKey[256];            // �O��̓��̓L�[�{�[�h�L�[
    static char nowKeyboardKey[256];            // ����̓��̓L�[�{�[�h�L�[
public:
    static bool KeyboardUpdate();               // �L�[�̍X�V
    static bool KeyboardClick(int inputKey);    // �{�^�����������u��
    static bool KeyboardPressed(int inputKey);  // �{�^���������Ă����
    static bool KeyboardRelease(int inputKey);  // �{�^���𗣂����u��
#endif // _ON_INPUT_KEYBOARD_

#ifdef _ON_INPUT_KEYBOARD_AND_JOYPAD1_
private:
    static int oldKeyAndPad1Key;                    // �O��̓��̓L�[�{�[�h&�R���g���[���[�P�L�[
    static int nowKeyAndPad1Key;                    // ����̓��̓L�[�{�[�h&�R���g���[���[�P�L�[
public:
    static bool KeyAndPad1Update();               // �L�[�̍X�V
    static bool KeyAndPad1Click(int inputKey);      // �{�^�����������u��
    static bool KeyAndPad1Pressed(int inputKey);    // �{�^���������Ă����
    static bool KeyAndPad1Release(int inputKey);    // �{�^���𗣂����u��
#endif // _ON_INPUT_KEYBOARD_AND_JOYPAD1_

#ifdef _ON_INPUT_JOYPAD1_
private:
    static int oldPad1Key;                  // �O��̓��̓R���g���[���[�P�L�[
    static int nowPad1Key;                  // ����̓��̓R���g���[���[�P�L�[
public:
    static bool Pad1Update();               // �L�[�̍X�V
    static bool Pad1Click(int inputKey);    // �{�^�����������u��
    static bool Pad1Pressed(int inputKey);  // �{�^���������Ă����
    static bool Pad1Release(int inputKey);  // �{�^���𗣂����u��
#endif // _ON_INPUT_JOYPAD1_

#ifdef _ON_INPUT_JOYPAD2_
private:
    static int oldPad2Key;                  // �O��̓��̓R���g���[���[�Q�L�[
    static int nowPad2Key;                  // ����̓��̓R���g���[���[�Q�L�[
public:
    static bool Pad2Update();               // �L�[�̍X�V
    static bool Pad2Click(int inputKey);    // �{�^�����������u��
    static bool Pad2Pressed(int inputKey);  // �{�^���������Ă����
    static bool Pad2Release(int inputKey);  // �{�^���𗣂����u��
#endif // _ON_INPUT_JOYPAD2_

#ifdef _ON_INPUT_JOYPAD3_
private:
    static int oldPad3Key;                  // �O��̓��̓R���g���[���[�R�L�[
    static int nowPad3Key;                  // ����̓��̓R���g���[���[�R�L�[
public:
    static bool Pad3Update();               // �L�[�̍X�V
    static bool Pad3Click(int inputKey);    // �{�^�����������u��
    static bool Pad3Pressed(int inputKey);  // �{�^���������Ă����
    static bool Pad3Release(int inputKey);  // �{�^���𗣂����u��
#endif // _ON_INPUT_JOYPAD3_

#ifdef _ON_INPUT_JOYPAD4_
private:
    static int oldPad4Key;                  // �O��̓��̓R���g���[���[�S�L�[
    static int nowPad4Key;                  // ����̓��̓R���g���[���[�S�L�[
public:
    static bool Pad4Update();               // �L�[�̍X�V
    static bool Pad4Click(int inputKey);    // �{�^�����������u��
    static bool Pad4Pressed(int inputKey);  // �{�^���������Ă����
    static bool Pad4Release(int inputKey);  // �{�^���𗣂����u��
#endif // _ON_INPUT_JOYPAD4_

#ifdef _ON_INPUT_PAD_KEYBOARD_
private:
    static int oldPadKeyboardKey;                   // �O��̓��̓p�b�h�L�[�{�[�h�L�[
    static int nowPadKeyboardKey;                   // ����̓��̓p�b�h�L�[�{�[�h�L�[
public:
    static bool PadKeyboardUpdate();               // �L�[�̍X�V
    static bool PadKeyboardClick(int inputKey);     // �{�^�����������u��
    static bool PadKeyboardPressed(int inputKey);   // �{�^���������Ă����
    static bool PadKeyboardRelease(int inputKey);   // �{�^���𗣂����u��
#endif // _ON_INPUT_PAD_KEYBOARD_
};

