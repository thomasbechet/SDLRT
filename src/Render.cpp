#include <Render.hpp>

#include <Constants.hpp>

void setPixel(SDL_Surface& surface, unsigned x, unsigned y, Uint8 r, Uint8 g, Uint8 b)
{
    int* ptr = (int*)surface.pixels;
    ptr[y * (surface.pitch / sizeof(int)) + x] = SDL_MapRGB(surface.format, r, g, b);
}

void Render::render(SDL_Surface& surface, Scene& scene)
{
    glm::mat4 inverse = scene.getCamera().getInverseVPMatrix();
    glm::vec3 position = scene.getCamera().getPosition();

    for(int x = 0; x < WIDTH; x++)
    {
        for(int y = 0; y < HEIGHT; y++)
        {
            glm::vec2 pos(x, y);
            
            glm::vec4 near = glm::vec4((pos.x - WIDTH_CENTER) / WIDTH, -1.0f * (pos.y - HEIGHT_CENTER) / HEIGHT, -1.0f, 1.0f);
            glm::vec4 far = glm::vec4((pos.x - WIDTH_CENTER) / WIDTH, -1.0f * (pos.y - HEIGHT_CENTER) / HEIGHT, 1.0f, 1.0f);
            glm::vec4 nearResult = inverse * near;
            glm::vec4 farResult = inverse * far;
            nearResult /= nearResult.w;
            farResult /= farResult.w;
            glm::vec3 dir = glm::normalize(glm::vec3(farResult - nearResult));
            
            Ray ray;
            ray.origin = position;
            ray.direction = dir;

            glm::vec3 lightSource(-5.0f, 5.0f, -5.0f);

            HitInfo hit;
            if(scene.intersect(ray, hit))
            {
                glm::vec3 color = hit.material.color;
                if(hit.material.reflect)
                {
                    const float rf = 0.9f;

                    Ray subRay;
                    subRay.origin = hit.position;
                    subRay.direction = glm::reflect(ray.direction, hit.normal);

                    HitInfo subHit;
                    if(scene.intersect(subRay, subHit))
                    {
                        color = color * (1.0f - rf) + subHit.material.color * rf;
                    }
                    else
                    {
                        color *= (1.0f - rf);
                    }
                }

                glm::vec3 L = glm::normalize(lightSource - hit.position);
                glm::vec3 diff = color * std::max(glm::dot(hit.normal, L), 0.0f);

                setPixel(surface, x, y, 
                    (unsigned)(diff.x * 255.0f),
                    (unsigned)(diff.y * 255.0f), 
                    (unsigned)(diff.z * 255.0f));
            }
            else
            {
                setPixel(surface, x, y, 0, 0, 0);
            }
        }
    }
}