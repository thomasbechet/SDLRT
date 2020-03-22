#include <Sphere.hpp>

#include <iostream>

Sphere::Sphere(float radius, glm::vec3 position, Material material) :
    m_radius(radius),
    m_position(position),
    m_material(material)
{

}

bool Sphere::intersect(Ray ray, HitInfo& info)
{
    glm::vec3 L = m_position - ray.origin;
    float tca = glm::dot(L, ray.direction);
    if(tca < 0) return false;
    float d2 = glm::dot(L, L) - tca * tca;
    if(d2 > m_radius) return false;
    float thc = std::sqrt(m_radius - d2);
    float t0 = tca - thc;
    float t1 = tca + thc;

    info.position = ray.origin + ray.direction * t0;
    info.normal = glm::normalize(info.position - m_position);
    info.distance = t0;
    info.material = m_material;

    return true;
}