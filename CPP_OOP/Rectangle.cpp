#include "Rectangle.h"

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