#include "ItemBase.h"

ItemBase::ItemBase(Location2D location, float radius, E_ITEM_TYPE type, Location2D speed)
    : SphereCollider(location, radius), type(type), speed(speed)
{

}

E_ITEM_TYPE ItemBase::GetType()
{
    return type;
}