#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

class textureManager{
    public:

    textureManager();
    ~textureManager();
    SDL_Texture* getTextureFromCache(const char* filePath); //searches the map for the texture

    SDL_Texture* addTexturetoCache(const char* filePath);

    void destroyCache(); //cleanup at the end of program

    private:
    std::map<const char*, SDL_Texture*> _textureMap;
};