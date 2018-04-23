
#ifndef INTERSECTION_H
#define INTERSECTION_H

#include "globalincludes.h"
#include "memory"


class intersection
{
public:
    intersection();

    //Vars
    Point3f pos;
    Normal3f nor;
    float t;
    std::shared_ptr<int*> objectHit;

};

#endif // INTERSECTION_H
