#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

class textureManager{
    public:

    static SDL_Texture* getTextureFromCache(const char* filePath); //searches the map for the texture

    static SDL_Texture* addTexturetoCache(const char* filePath);

    static void destroyCache(); //cleanup at the end of program

    private:
    static std::map<const char*, SDL_Texture*> textureMap;

};