#include <Camera.hpp>

#include <constants.hpp>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Camera::Camera(glm::vec3 position, glm::vec3 look_at) :
    m_position(position)
{
    glm::vec3 direction = look_at - position;
    glm::vec3 left = glm::cross(
        direction,
        glm::vec3(0.0f, 1.0f, 0.0f)
    );

    glm::mat4 viewMatrix = glm::lookAt(
        position,
        look_at,
        glm::normalize(glm::cross(left, direction))
    );

    glm::mat4 projectionMatrix = glm::perspective(
        glm::radians(70.0f),
        (float)WIDTH / (float)HEIGHT,
        0.01f,
        100.0f
    );

    m_inverse_vp_matrix = glm::inverse(projectionMatrix * viewMatrix);
}

glm::mat4 Camera::inverseMatrix() const
{
    return m_inverse_vp_matrix;
}
glm::vec3 Camera::getPosition() const
{
    return m_position;
}

Ray Camera::getRay(const glm::vec2& position) const
{
    return Ray {
        origin: m_position,
        direction: glm::normalize(glm::vec3(
            position.x,
            position.y,
            -1.0f
        ))
    };
}