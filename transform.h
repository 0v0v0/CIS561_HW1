#pragma once

#ifndef TRANSFORM_H
#define TRANSFORM_H
#include "globalincludes.h"


class Transform
{
public:
    //Constructor
    Transform();
    Transform(glm::vec3 T,glm::vec3 R, glm::vec3 S);

    //Vars
    glm::vec3 pos;
    glm::vec3 rot;
    glm::vec3 scale;
    //Matrix, will be updated according to vars
    glm::mat4 world_trans;
    glm::mat4 i_world_trans;
    glm::mat3 i_world_trans_T;
    //Functions:
    update_mat();//Update Matrix.

};

#endif // TRANSFORM_H
