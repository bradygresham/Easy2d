#include "ResourceManager.h"

textureManager ResourceManager::_textureCache;

SDL_Texture* ResourceManager::getTextureFromCache(SDL_Renderer* renderer, const char* filePath)
{
    return _textureCache.getTextureFromCache(renderer, filePath);
}

void ResourceManager::destroyCache()
{
    _textureCache.destroyCache();
}