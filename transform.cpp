#include "transform.h"

Transform::Transform()
{
    pos=glm::vec3(0);
    rot=glm::vec3(0);
    scale=glm::vec3(1);
}

Transform::Transform(glm::vec3 T, glm::vec3 R, glm::vec3 S)
{
    pos=T;
    rot=R;
    scale=S;
}

Transform::update_mat()
{
    /*
    glm::vec4 pos4=glm::vec4(pos,1);
    glm::vec4 rot4=glm::vec4(rot,1);
    glm::vec4 scale4=glm::vec4(scale,1);
    */

    glm::mat4 pos44 = glm::translate(glm::mat4(1.0f),pos);
    glm::mat4 rot44=
            glm::rotate(glm::mat4(1.0f),rot.x,glm::vec3(1,0,0)) *
            glm::rotate(glm::mat4(1.0f),rot.y,glm::vec3(0,1,0)) *
            glm::rotate(glm::mat4(1.0f),rot.z,glm::vec3(0,0,1));

    glm::mat4 scale44 = glm::scale(glm::mat4(1.0f),scale);

    //Update world transform
    world_trans=pos44*rot44*scale44;
    //Update inverse world transform
    i_world_trans=glm::inverse(world_trans);
    //Update transposed inverse world transform
    glm::mat4 i_world_trans_T4=glm::transpose(i_world_trans);
    i_world_trans_T=glm::mat3(i_world_trans_T4);

}
