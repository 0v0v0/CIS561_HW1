#pragma once
#ifndef CAMERA_H
#define CAMERA_H
#include "globalincludes.h"

class camera
{
public:
    camera();

    Point3f eye_pos;
    Vector3f look_dir;
    Vector3f world_up;
    float FOV;
    float near_clip;
    float far_clip;

    float width,height;

    glm::mat4 get_trans_mat4();
};

#endif // CAMERA_H
