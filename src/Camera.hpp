#pragma once

#include <Ray.hpp>

#include <glm/glm.hpp>

class Camera
{
public:
    Camera(glm::vec3 position, glm::vec3 lookat);

    glm::mat4 inverseMatrix() const;
    glm::vec3 getPosition() const;
    Ray getRay(const glm::vec2& position) const;

private:
    glm::mat4 m_inverse_vp_matrix;
    glm::vec3 m_position;
};