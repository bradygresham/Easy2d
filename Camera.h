#pragma once
#include <SDL2/SDL.h>
class Camera{
    public:
    Camera();
    Camera(int w, int h);
    ~Camera();

    void init_camera(int w, int h);
    void applyCamera(SDL_Renderer * renderer);
    void setZoom(double new_zoom);
    void move(int dx, int dy);
    
    private:
    SDL_Rect _viewport;
    double _zoom;
    int _x, _y;
    

};