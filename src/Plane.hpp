#pragma once

#include <Object.hpp>
#include <Material.hpp>

class Plane : public Object
{
public:
    Plane(glm::vec3 position, glm::vec3 normal);

    bool intersect(Ray ray, HitInfo& info) override;

private:
    glm::vec3 m_position;
    glm::vec3 m_normal;
    Material m_material;
};