#pragma once

#include "Shape.h"
#include "PaintCost.h"

class Rectangle
    : public Shape
    , public PaintCost
{
public:
    int getArea()
    {
        return (width * height);
    }
};