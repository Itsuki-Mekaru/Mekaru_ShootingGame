#pragma once

class KeyManager
{
private:
    static char oldKey[256];
    static char nowKey[256];

    static int oldMouse;
    static int nowMouse;

private:
    KeyManager() = default;

public:
    static void Update();
    static bool OnKeyClicked(int key);
    static bool OnKeyReleased(int key);
    static bool OnKeyPressed(int key);

    static bool OnMouseClicked(int key);
    static bool OnMouseReleased(int key);
    static bool OnMousePressed(int key);
};