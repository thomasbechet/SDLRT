#pragma once

#include <glm/glm.hpp>

class Camera
{
public:
    Camera(glm::vec3 position, glm::vec3 lookAt);

    glm::mat4 getInverseVPMatrix() const;
    glm::vec3 getPosition() const;

private:
    glm::mat4 m_inverseVPMatrix;
    glm::vec3 m_position;
};