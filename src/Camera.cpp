#include <Camera.hpp>

#include <Constants.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec3 position, glm::vec3 lookAt) :
    m_position(position)
{
    glm::vec3 direction = lookAt - position;
    glm::vec3 left = glm::cross(
        direction,
        glm::vec3(0.0f, 1.0f, 0.0f)
    );

    glm::mat4 viewMatrix = glm::lookAt(
        position,
        lookAt,
        glm::normalize(glm::cross(left, direction))
    );

    glm::mat4 projectionMatrix = glm::perspective(
        glm::radians(90.0f),
        (float)WIDTH / (float)HEIGHT,
        0.01f,
        100.0f 
    );

    m_inverseVPMatrix = glm::inverse(projectionMatrix * viewMatrix);
}

glm::mat4 Camera::getInverseVPMatrix() const
{
    return m_inverseVPMatrix;
}
glm::vec3 Camera::getPosition() const
{
    return m_position;
}