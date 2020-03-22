#pragma once

#include <Material.hpp>

#include <glm/glm.hpp>

struct Ray
{
    glm::vec3 origin;
    glm::vec3 direction;
};

struct HitInfo
{
    glm::vec3 position;
    glm::vec3 normal;
    float distance;
    Material material;
};