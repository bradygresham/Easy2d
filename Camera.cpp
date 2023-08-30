#include "Camera.h"

Camera::Camera()
: _viewport({0, 0, 0, 0}), _zoom(1.0), _x(0), _y(0) {}


Camera::Camera(int w, int h)
: _viewport({0, 0, w, h}), _zoom(1.0), _x(0), _y(0) {}

Camera::~Camera(){}

void Camera::init_camera(int w, int h)
{
    _viewport.w = w;
    _viewport.h = h;
}

void Camera::applyCamera(SDL_Renderer *renderer)
{
    SDL_RenderSetViewport(renderer, &_viewport);
}

void Camera::setZoom(double new_zoom)
{
    _zoom = new_zoom;
    _viewport.w = static_cast<int>(_viewport.w / _zoom);
    _viewport.h = static_cast<int>(_viewport.h / _zoom);
}

void Camera::move(int dx, int dy)
{
    _x += dx;
    _y += dy;
    _viewport.x = _x;
    _viewport.y = _y;
}
