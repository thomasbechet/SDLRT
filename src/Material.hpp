#pragma once

#include <glm/glm.hpp>

struct Material
{
    glm::vec3 color = glm::vec3(1.0f, 1.0f, 1.0f);
    bool reflect = true;
};