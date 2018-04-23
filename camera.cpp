#include "camera.h"

camera::camera()
{

}

glm::mat4 camera::get_trans_mat4()
{
    glm::mat4 aaa=glm::perspectiveFov(FOV,width,height,near_clip,far_clip);

    glm::mat4 bbb=glm::perspective(FOV,width/height,near_clip,far_clip);

    return aaa;
}
