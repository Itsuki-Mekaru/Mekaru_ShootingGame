#include "Location2D.h"
#include <math.h>

Location2D::Location2D(float x, float y) : x(x), y(y)
{}

Location2D::Location2D(const Location2D& location) : x(location.x), y(location.y)
{}

Location2D Location2D::GetLocation()
{
    return (*this);
}

float Location2D::GetLength()
{
    float ret = sqrtf((x * x) + (y * y));
    return ret;
}

Location2D& Location2D::operator = (const Location2D& location)
{
    this->x = location.x;
    this->y = location.y;
    return (*this);
}

const Location2D Location2D::operator + (const Location2D& location) const
{
    float x = this->x + location.x;
    float y = this->y + location.y;
    return Location2D(x, y);
}

const Location2D Location2D::operator - (const Location2D& location) const
{
    float x = this->x - location.x;
    float y = this->y - location.y;
    return Location2D(x, y);
}

const Location2D Location2D::operator * (const Location2D& location) const
{
    float x = this->x * location.x;
    float y = this->y * location.y;
    return Location2D(x, y);
}

const Location2D Location2D::operator / (const Location2D& location) const
{
    float x = location.x == 0 ? 0 : this->x / location.x;
    float y = location.y == 0 ? 0 : this->y / location.y;
    return Location2D(x, y);
}

Location2D& Location2D::operator += (const Location2D& location)
{
    this->x += location.x;
    this->y += location.y;
    return (*this);
}

Location2D& Location2D::operator -= (const Location2D& location)
{
    this->x -= location.x;
    this->y -= location.y;
    return (*this);
}

Location2D& Location2D::operator *= (const Location2D& location)
{
    this->x *= location.x;
    this->y *= location.y;
    return (*this);
}

Location2D& Location2D::operator /= (const Location2D& location)
{
    this->x = location.x == 0 ? 0 : this->x / location.x;
    this->y = location.y == 0 ? 0 : this->y / location.y;
    return (*this);
}

bool Location2D::operator == (const Location2D& location) const
{
    bool ret = ((this->x == location.x) && (this->y == location.y));
    return ret;
}

bool Location2D::operator != (const Location2D& location) const
{
    bool ret = ((this->x != location.x) || (this->y != location.y));
    return ret;
}