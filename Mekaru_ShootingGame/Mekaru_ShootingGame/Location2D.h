#pragma once

class Location2D
{
public:
    float x;
    float y;

public:
    Location2D(float x = 0.f, float y = 0.f);
    Location2D(const Location2D& location);
    virtual ~Location2D() = default;

public:
    Location2D GetLocation();
    float GetLength();

    Location2D& operator = (const Location2D& location);

    const Location2D operator + (const Location2D& location) const;
    const Location2D operator - (const Location2D& location) const;
    const Location2D operator * (const Location2D& location) const;
    const Location2D operator / (const Location2D& location) const;

    Location2D& operator += (const Location2D& location);
    Location2D& operator -= (const Location2D& location);
    Location2D& operator *= (const Location2D& location);
    Location2D& operator/=(const Location2D& location);

    bool operator == (const Location2D& location) const;
    bool operator != (const Location2D& location) const;
};
