#pragma once

#include <Ray.hpp>

class Object
{
public:
    virtual ~Object() = default;
    virtual bool intersect(Ray ray, HitInfo& info) = 0;
};