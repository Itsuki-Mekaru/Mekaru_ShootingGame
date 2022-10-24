#include "DxLib.h"
#include "KeyManager.h"

char KeyManager::oldKey[256];
char KeyManager::nowKey[256]; 

int KeyManager::oldMouse;
int KeyManager::nowMouse;

void KeyManager::Update()
{
    for(int i = 0; i < 256; i++)
    {
        oldKey[i] = nowKey[i];
    }

    if(GetHitKeyStateAll(nowKey) == -1)
    {
        throw -1;
    }

    oldMouse = nowMouse;
    nowMouse = GetMouseInput();
}

bool KeyManager::OnKeyClicked(int key)
{
    bool ret = ((nowKey[key] == 1) && (oldKey[key] != 1));
    return ret;
}

bool KeyManager::OnKeyReleased(int key)
{
    // ボタンを離した瞬間
    bool ret = ((nowKey[key] != 1) && (oldKey[key] == 1));
    return ret;
}

bool KeyManager::OnKeyPressed(int key)
{
    // ボタンを押している間
    bool ret = (nowKey[key] == 1);
    return ret;
}

bool KeyManager::OnMouseClicked(int key)
{
    bool ret = ((nowMouse & key) && (~oldMouse & key));
    return ret;
}

bool KeyManager::OnMouseReleased(int key)
{
    // ボタンを離した瞬間
    bool ret = ((~nowMouse & key) && (oldMouse & key));
    return ret;
}

bool KeyManager::OnMousePressed(int key)
{
    // ボタンを押している間
    bool ret = (nowMouse & key);
    return ret;
}