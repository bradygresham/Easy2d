#pragma once
#include "textureManager.h"
#include <SDL2/SDL.h>
class ResourceManager
{
    public:
    static SDL_Texture* getTextureFromCache(const char* filePath); 
    static void destroyCache();
    private:
    static textureManager _textureCache;
};