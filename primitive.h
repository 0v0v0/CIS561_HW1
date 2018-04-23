
#ifndef PRIMITIVE_H
#define PRIMITIVE_H

#include <memory>
#include "globalincludes.h"
#include "shape.h"
#include "ray.h"
#include "intersection.h"


class primitive
{
public:

    primitive();
    QString name;
    glm::mat4 trans_mat4;

    std::shared_ptr<shape> shape;


    //Functions
    bool getIntersection(Ray ray, intersection* intersect) const;


};

#endif // PRIMITIVE_H
