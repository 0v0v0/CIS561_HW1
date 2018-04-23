#ifndef SQUAREPLANE_H
#define SQUAREPLANE_H

#include "shape.h"

class SquarePlane :public shape
{
public:
    SquarePlane();
    float len;
    Normal3f nor;
    glm::vec3 vertex[4];

    //Functions:
    //a unit SquarePlane should be centered at the origin, have side lengths of 1, and have its normal aligned with the Z-axis.
    bool getIntersection(Ray ray, intersection* intersect) const;
    void update_vertex();


};

#endif // SQUAREPLANE_H
