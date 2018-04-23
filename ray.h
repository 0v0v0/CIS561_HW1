#pragma once
#ifndef RAY_H
#define RAY_H
#include "globalincludes.h"

class Ray
{

public:
    Ray(){}

    //Vars
    Point3f origin;
    Vector3f dir;

    //Functions:
    Ray Transform(glm::mat4 Transform4);
};


#endif // RAY_H
