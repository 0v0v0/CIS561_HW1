#include "squareplane.h"

SquarePlane::SquarePlane()
{
    trans=Transform();
    len=0.25f;
}

void SquarePlane::update_vertex()
{
    vertex[0]=trans.pos+glm::vec3(-len,-len,0);
    vertex[1]=trans.pos+glm::vec3(len,-len,0);
    vertex[2]=trans.pos+glm::vec3(-len,len,0);
    vertex[3]=trans.pos+glm::vec3(len,len,0);

    for(int i=0;i<4;i++)
    {
        vertex[i]=glm::vec3(trans.world_trans*glm::vec4(vertex[i],1.0f));
    }
    nor=glm::normalize(glm::vec3(trans.world_trans*glm::vec4(nor,1)));
}

bool Barycentric(glm::vec3 p, glm::vec3 a, glm::vec3 b, glm::vec3 c)
{
    glm::vec3 v0 = b - a;
    glm::vec3 v1 = c - a;
    glm::vec3 v2 = p - a;
    float d00 = glm::dot(v0, v0);
    float d01 = glm::dot(v0, v1);
    float d11 = glm::dot(v1, v1);
    float d20 = glm::dot(v2, v0);
    float d21 = glm::dot(v2, v1);
    float denom = d00 * d11 - d01 * d01;
    float v = (d11 * d20 - d01 * d21) / denom;
    float w = (d00 * d21 - d01 * d20) / denom;
    float u = 1.0f - v - w;

    if(u<0)
    {
        return false;
    }

    return true;
}

bool SquarePlane::getIntersection(Ray ray, intersection* intersect) const
{
    ray.Transform(trans.i_world_trans);

    float d=glm::dot(ray.dir-ray.origin,trans.rot);

    if(d>0)
    {
        glm::vec3 dis=trans.pos-ray.origin;
        float t=glm::dot(dis,nor)/d;

        glm::vec3 pos=ray.origin+ray.dir*t; //position of intersect

        if( Barycentric(pos,vertex[0],vertex[1],vertex[2]) ||
            Barycentric(pos,vertex[3],vertex[1],vertex[2]) )
        {
            intersect->nor=nor;
            intersect->t=t;
            return true;
        }

    }

    return false;
}
