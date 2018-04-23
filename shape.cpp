#include "shape.h"

shape::shape()
{
    trans=Transform();
}

shape::shape(Transform init)
{
    trans=init;
}
