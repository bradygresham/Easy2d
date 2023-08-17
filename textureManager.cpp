#include "textureManager.h"
#include "Error.h"

SDL_Texture *textureManager::getTextureFromCache(const char *filePath)
{
    //use filePath as key to search for texture
    auto mit = textureMap.find(filePath); 
    //include error checking so we don't set computer on fire
    if (mit == textureMap.end())
    {
        addTexturetoCache(filePath); //also returns the new texture if it was made.
    }
    //if returns nullptr then we add the filePath to the map with the image stored as the texture
    return mit->second;
}

SDL_Texture *textureManager::addTexturetoCache(const char* filePath)
{
    SDL_Texture* newTexture = IMG_LoadTexture(nullptr, filePath);
    if (newTexture == NULL) //error checking
    {
        SDL_DestroyTexture(newTexture);
        errorAndFilePath("Error in textureManager.cpp \n Texture not created:", filePath);
        return NULL; 
    }
    
    textureMap.insert(std::make_pair(filePath, newTexture));
    return newTexture;
    

}

void textureManager::destroyCache()
{
    std::map<const char*, SDL_Texture*>::iterator mit;
    
    for (mit = textureMap.begin(); mit != textureMap.end(); mit++)
    {
        SDL_DestroyTexture(mit->second); 
    }
}
