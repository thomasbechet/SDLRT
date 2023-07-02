#include <Scene.hpp>

#include <Sphere.hpp>
#include <Plane.hpp>

Scene::Scene() :
    m_camera(glm::vec3(0.0f, 0.5f, -6.0f), glm::vec3(0.0f, 0.0f, 0.0f))
{
    m_objects.emplace_back(std::make_unique<Sphere>(1.0f, glm::vec3(-2.0f, 0.0f, 0.0f), Material {
        glm::vec3(0.5f, 0.2f, 0.2f),
        false
    }));
    m_objects.emplace_back(std::make_unique<Sphere>(1.0f, glm::vec3(0.0f, 0.0f, 0.0f)));
    m_objects.emplace_back(std::make_unique<Sphere>(1.0f, glm::vec3(2.0f, 0.0f, 0.0f), Material {
        glm::vec3(0.2f, 0.5f, 0.2f),
        false
    }));

    m_objects.emplace_back(std::make_unique<Plane>(glm::vec3(0.0f, -5.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f), Material {
        glm::vec3(1.0f, 1.0f, 1.0f),
        true
    }));
}

void Scene::update()
{
    
}
bool Scene::intersect(Ray ray, HitInfo& info)
{
    bool hit = false;
    for(auto& it : m_objects)
    {
        HitInfo hitInfo;
        if(it->intersect(ray, hitInfo))
        {
            if(hitInfo.distance < info.distance || !hit)
            {
                info = hitInfo;
                hit = true;
            }
        }
    }

    return hit;
}
std::vector<std::unique_ptr<Object>>& Scene::getObjects()
{
    return m_objects;
}
Camera& Scene::getCamera()
{
    return m_camera;
}