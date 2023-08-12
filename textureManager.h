#pragma once

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <map>
#include <string>

class textureManager{

    textureManager();
    //textureManager(const char* textureList[]);
    ~textureManager();
    
    static std::map<const char*, SDL_Texture*> textureMap;

    static SDL_Texture* getTexture(const char* filePath); //searches the map for the texture


};