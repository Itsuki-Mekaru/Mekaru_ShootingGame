#pragma once
#include "SphereCollider.h"
#include "E_ITEM_TYPE.h"

class ItemBase : public SphereCollider
{
private:
    E_ITEM_TYPE type;

protected:
    Location2D speed;

public:
    ItemBase(Location2D location, float radius, E_ITEM_TYPE type, Location2D speed);

public:
    virtual void Update() = 0;
    virtual void Draw() = 0;
    E_ITEM_TYPE GetType();
};

