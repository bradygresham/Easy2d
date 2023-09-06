#pragma once
#include <SDL2/SDL.h>
class Camera2D{
    public:
    Camera2D();
    Camera2D(int w, int h);
    ~Camera2D();

    void init_camera(int w, int h);
    void applyCamera(SDL_Renderer * renderer);
    void setZoom(double new_zoom);
    void setPosition(int x, int y);
    void move(int dx, int dy);
    
    private:
    SDL_Rect _viewport;
    double _zoom;
    int _x, _y;
    

};