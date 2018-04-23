#pragma once

#ifndef SHAPE_H
#define SHAPE_H

#include "globalincludes.h"
#include "transform.h"
#include "intersection.h"
#include "ray.h"

class shape
{
public:
    //Constructor
    shape();
    shape(Transform init);

    //Vars
    Transform trans;

    //Functions
    virtual bool getIntersection(Ray ray, intersection* intersect) const=0;

};

#endif // SHAPE_H
