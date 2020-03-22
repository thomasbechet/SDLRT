#include <iostream>

#include <Constants.hpp>
#include <Scene.hpp>
#include <Ray.hpp>
#include <Render.hpp>

#include <SDL2/SDL.h>

int main(int argc, char* argv[])
{
    //Initialize window
    if(SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        std::cout << "SDL failed to initialized." << std::endl;
        std::cout << SDL_GetError() << std::endl;
        return 0;
    }

    //Create scene
    Scene scene;

    //Create window and get the surface window
    SDL_Window* window = nullptr;
    SDL_Surface* surface = nullptr;

    if(GENERATE_BMP_IMAGE)
    {
        Uint32 rmask, gmask, bmask, amask;
        #if SDL_BYTEORDER == SDL_BIG_ENDIAN
            rmask = 0xff000000;
            gmask = 0x00ff0000;
            bmask = 0x0000ff00;
            amask = 0x000000ff;
        #else
            rmask = 0x000000ff;
            gmask = 0x0000ff00;
            bmask = 0x00ff0000;
            amask = 0xff000000;
        #endif
        surface = SDL_CreateRGBSurface(0, WIDTH, HEIGHT, 32, rmask, gmask, bmask, amask);
        if(surface == nullptr)
        {
            std::cout << "SDL failed to create surface:" << std::endl;
            std::cout << SDL_GetError() << std::endl;
            return 0;
        }

        Render::render(*surface, scene);
        SDL_SaveBMP(surface, "out.bmp");
        SDL_FreeSurface(surface);
    }
    else
    {
        window = SDL_CreateWindow("RTSDL", 100, 100, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
        if(window == nullptr)
        {
            std::cout << "SDL failed to create window:" << std::endl;
            std::cout << SDL_GetError() << std::endl;
            SDL_Quit();
            return 0;
        }
        SDL_GL_SetSwapInterval(1);
        surface = SDL_GetWindowSurface(window);

        //Update surface window
        bool quit = false;
        while(!quit)
        {
            //Handle only quit event
            SDL_Event event;
            while(SDL_PollEvent(&event)) if(event.type == SDL_QUIT) quit = true;

            scene.update();
            Render::render(*surface, scene);
            SDL_UpdateWindowSurface(window);
        }
        SDL_DestroyWindow(window);
    }
    
    SDL_Quit();

    return 0;
}