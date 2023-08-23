#pragma once
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
class Sprite{
    public:
    Sprite();
    ~Sprite();

    int getX() {return _xCoord;}
    int getY() {return _yCoord;}
    int getW() {return _width;}
    int getH() {return _height;}

    SDL_Rect getSource() {return _sourceRect;}
    SDL_Rect getDestination() {return _destinationRect;}
    
    SDL_RendererFlip getFlip() {return _flip;}

    SDL_Texture* getTexture();
    void setTexture(); //possibly needs to use the texture manager
    void setDestination();

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
    SDL_Texture* _texture; //make this our own texture class

};