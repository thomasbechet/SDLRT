#pragma once

#include <Object.hpp>
#include <Material.hpp>

class Sphere : public Object
{
public:
    Sphere(float radius, glm::vec3 position, Material material = Material());
    
    bool intersect(Ray ray, HitInfo& info) override;

private:
    float m_radius;
    glm::vec3 m_position;
    Material m_material;
};