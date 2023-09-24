#pragma once
#include <unordered_map>
class InputManager{
    public:
    InputManager();
    ~InputManager();

    void keyPress(unsigned int keyID);
    void keyRelease(unsigned int keyID);

    bool isKeyPressed(unsigned int keyID);
    //add mouse control

    private:
    std::unordered_map <unsigned int, bool> _keyMap;
    
};