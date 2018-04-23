#pragma once

#ifndef SCENE_H
#define SCENE_H
#include "globalincludes.h"
#include "QList"
#include "primitive.h"
#include "ray.h"
#include "intersection.h"
#include "memory"
#include "camera.h"


class Scene
{
public:
    Scene();

    QList<std::shared_ptr<primitive>> objects;

    QList<camera>cam;

    bool getIntersection(Ray ray, intersection* intersect) const;



};

#endif // SCENE_H
