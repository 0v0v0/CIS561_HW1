#ifndef SPHERE_H
#define SPHERE_H
#include "shape.h"

class sphere : public shape
{
public:
    sphere();

    float r;//radious

    //Functions:
    //A unit Sphere should be assumed to be centered at the origin and have a radius of 0.5
    bool getIntersection(Ray ray, intersection* intersect) const;
};

#endif // SPHERE_H
