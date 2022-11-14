#pragma once
#include "ItemBase.h"

class HpPotion : public ItemBase
{
private:
    int healPower;

public:
    HpPotion(Location2D location);

public:
    virtual void Update();
    virtual void Draw();
};

