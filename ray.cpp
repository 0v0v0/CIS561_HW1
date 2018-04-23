#include "ray.h"

Ray Ray::Transform(glm::mat4 Transform4)
{
    glm::vec4 origin4=glm::vec4(origin,0);
    glm::vec4 dir4=glm::vec4(dir,0);

    glm::vec4 trans_origin4=Transform4*origin4;
    glm::vec4 trans_dir4=Transform4*dir4;

    Ray result;
    result.origin=glm::vec3(trans_origin4);
    result.dir=glm::vec3(trans_dir4);

    return result;
}



