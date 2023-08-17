#include "ResourceManager.h"

textureManager ResourceManager::_textureCache;

SDL_Texture* ResourceManager::getTextureFromCache(const char* filePath)
{
    return _textureCache.getTextureFromCache(filePath);
}