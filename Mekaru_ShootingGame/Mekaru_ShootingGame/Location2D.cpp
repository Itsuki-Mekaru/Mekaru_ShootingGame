#include "Location2D.h"
#include <math.h>

Location2D::Location2D(float x, float y) : x(x), y(y)
{

}

Location2D Location2D::GetLocation()
{
    return (*this);
}

float Location2D::GetLength()
{
    float ret = sqrtf((x * x) + (y * y));
    return ret;
}

bool Location2D::operator==(Location2D& location)
{
    bool ret = ((this->x == location.x) && (this->y == location.y));
    return ret;
}

Location2D& Location2D::operator=(Location2D& location)
{
    this->x = location.x;
    this->y = location.y;
    return (*this);
}

Location2D& Location2D::operator+(Location2D& location)
{
    Location2D ret = Location2D((this->x + location.x), (this->y + location.y));
    return ret;
}

Location2D& Location2D::operator+=(Location2D& location)
{
    this->x += location.x;
    this->y += location.y;
    return (*this);
}

Location2D& Location2D::operator-(Location2D& location)
{
    Location2D ret = Location2D((this->x - location.x), (this->y - location.y));
    return ret;
}

Location2D& Location2D::operator-(Location2D location)
{
    Location2D ret = Location2D((this->x - location.x), (this->y - location.y));
    return ret;
}