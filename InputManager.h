#pragma once
#include <SDL2/SDL.h>
#include <R2R_keycode.h>
class InputManager{
    public:
    InputManager();
    ~InputManager();

    void keyPress(unsigned int keyID);
    private:
    
};