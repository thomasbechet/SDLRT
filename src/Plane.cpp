#include <Plane.hpp>

Plane::Plane(glm::vec3 position, glm::vec3 normal) :
    m_position(position),
    m_normal(glm::normalize(normal))
{

}

bool Plane::intersect(Ray ray, HitInfo& info)
{
    float denom = glm::dot(m_normal, ray.direction);
    if (abs(denom) > 0.0001f)
    {
        float t = glm::dot((m_position - ray.origin), m_normal) / denom;
        if (t >= 0)
        {
            info.distance = 100000.0f;
            info.normal = m_normal;
            info.position = m_position;
            return true;
        }
    }
    return false;
}