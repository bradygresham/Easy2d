#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class Sprite{
    public:
    Sprite();
    ~Sprite();

    int getX();
    int getY();
    int getW();
    int getH();

    SDL_Rect getSource();
    SDL_Rect getDestination();
    void setDestination();
    SDL_RendererFlip getFlip();
    SDL_Texture* getTexture();
    void setTexture(); //possibly needs to use the texture manager

    private:
    int _xCoord;
    int _yCoord;
    int _width;
    int _height;
    // initialize these with the above integers
    SDL_Rect _sourceRect;
    SDL_Rect _destinationRect;
    //

    SDL_RendererFlip _flip;
    SDL_Texture* _texture;

};