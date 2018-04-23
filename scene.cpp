#include "scene.h"

Scene::Scene()
{

}

bool Scene::getIntersection(Ray ray, intersection* intersect) const
{
    intersection hit,min_hit;
    min_hit.t=100000;//A very large number

    bool has_intersect=false;
    for(int i=0;i<objects.length();i++)
    {
        if(objects.at(i).get()->getIntersection(ray,&hit))
        {
            has_intersect=true;
            if(hit.t<min_hit.t)
            {
                min_hit=hit;
            }
        }

    }

    if(has_intersect)//revise intersect
    {
        intersect->nor=min_hit.nor;
        intersect->objectHit=min_hit.objectHit;
        intersect->pos=min_hit.pos;
        intersect->t=min_hit.t;
    }

    return has_intersect;
}
