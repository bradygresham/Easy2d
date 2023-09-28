#include "Camera2D.h"

Camera2D::Camera2D()
: _viewport({0, 0, 0, 0}), _zoom(1.0), _x(0), _y(0) {}


Camera2D::Camera2D(int w, int h)
: _viewport({0, 0, w, h}), _zoom(1.0), _x(0), _y(0) {}

Camera2D::~Camera2D(){}

void Camera2D::init_camera(int w, int h)
{
    _viewport.w = w;
    _viewport.h = h;
}

void Camera2D::applyCamera(SDL_Renderer *renderer)
{
    SDL_RenderSetViewport(renderer, &_viewport);
}

void Camera2D::setZoom(double new_zoom)
{
    _zoom = new_zoom;
    int prevW = _viewport.w;
    int prevH = _viewport.h;
    _viewport.w = static_cast<int>(_viewport.w / _zoom);
    _viewport.h = static_cast<int>(_viewport.h / _zoom);
    //adjust x and y to zoom in at the center
    //if w = 1000 and h = 1000 and we zoom in by 3.5 w= 3500 and h = 3500
    _x += (prevW - _viewport.w) / 2;
    _y += (prevH - _viewport.h) / 2;
    _viewport.x = _x;
    _viewport.y = _y;
}

void Camera2D::setPosition(int x, int y)
{
    _x = x;
    _y = y;
    _viewport.x = _x;
    _viewport.y = _y;
}

void Camera2D::move(int dx, int dy)
{
    _x += dx;
    _y += dy;
    _viewport.x = _x;
    _viewport.y = _y;
}
