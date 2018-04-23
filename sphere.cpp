#include "sphere.h"
#include "algorithm"

bool Quadratic(float a, float b, float c, float *t0, float *t1);

sphere::sphere()
{
    trans=Transform();
    r=1;    //Default;
}

bool sphere::getIntersection(Ray ray, intersection* intersect) const
{

    ray.Transform(trans.i_world_trans);

    // Compute quadratic sphere coefficients

    // Initialize _EFloat_ ray coordinate values
    float ox=ray.origin.x, oy=ray.origin.y, oz=ray.origin.z;
    float dx=ray.dir.x, dy=ray.dir.y, dz=ray.dir.z;
    float a = dx * dx + dy * dy + dz * dz;
    float b = 2 * (dx * ox + dy * oy + dz * oz);
    float c = ox * ox + oy * oy + oz * oz -r*r;

    // Solve quadratic equation for _t_ values
    float t0, t1;
    if (!Quadratic(a, b, c, &t0, &t1))
    {
        return false;
    }

    // Check quadric shape _t0_ and _t1_ for nearest intersection

    float t = t0;

    if (t <= 0)
    {
        t = t1;
    }

    glm::vec3 point=ray.origin+ray.dir*t;

    //intersect->objectHit=this;
    intersect->pos=point;
    intersect->t=t;
    intersect->nor=glm::normalize(point*trans.scale);

    return true;
}

//Solve roots
bool Quadratic(float a, float b, float c, float *t0, float *t1)
{
    // Find quadratic discriminant
    double discrim = (double)b * (double)b - 4 * (double)a * (double)c;
    if (discrim < 0)
    {
        return false;
    }
    double rootDiscrim = std::sqrt(discrim);

    // Compute quadratic _t_ values
    double q;
    if (b < 0)
    {
        q = -.5 * (b - rootDiscrim);
    }
    else
    {
        q = -.5 * (b + rootDiscrim);
    }
    *t0 = q / a;
    *t1 = c / q;

    if (*t0 > *t1)
    {
        std::swap(*t0, *t1);
    }

    return true;
}










