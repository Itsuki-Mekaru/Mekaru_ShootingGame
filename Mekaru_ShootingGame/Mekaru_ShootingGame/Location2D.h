#pragma once
class Location2D
{
public:
    float x;
    float y;

public:
    Location2D(float x = 0.f, float y = 0.f);

public:
    Location2D GetLocation();
    float GetLength();

    bool operator==(Location2D& location);
    Location2D& operator = (Location2D& location);
    Location2D& operator + (Location2D& location);
    Location2D& operator += (Location2D& location);
    Location2D& operator - (Location2D& location);
    Location2D& operator - (Location2D location);

};

