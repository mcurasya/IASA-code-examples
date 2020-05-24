#pragma once

class Vector
{
public:
    float x;
    float y;
    Vector(float x, float y);
    ~Vector();
    void add(const Vector &vec);
    void scale(float alpha);
};
