#pragma once

#include <SDL2/SDL.h>
#include <Scene.hpp>

class Render
{
public:
    static void render(SDL_Surface& surface, Scene& scene);
};