#pragma once

#include <Object.hpp>
#include <Camera.hpp>

#include <memory>
#include <vector>

class Scene
{
public:
    Scene();

    void update();
    bool intersect(Ray ray, HitInfo& info);
    std::vector<std::unique_ptr<Object>>& getObjects();
    Camera& getCamera();

private:
    std::vector<std::unique_ptr<Object>> m_objects;
    Camera m_camera;
};