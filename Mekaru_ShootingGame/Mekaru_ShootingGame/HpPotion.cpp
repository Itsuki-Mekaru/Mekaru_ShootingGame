#include "HpPotion.h"
#include "DxLib.h"

HpPotion::HpPotion(Location2D location)
    :ItemBase(location, 5, E_ITEM_TYPE::HP_POTION, Location2D{0.f, 0.5f}), healPower(2)
{

}

void HpPotion::Update()
{
    Location2D newLocation = GetLocation();
    newLocation.y += speed.y;
    SetLocation(newLocation);
}

void HpPotion::Draw()
{
    DrawCircle(GetLocation().x, GetLocation().y, GetRadius(), GetColor(255, 255, 255));
}