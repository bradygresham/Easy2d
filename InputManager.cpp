#include "InputManager.h"

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
}

void InputManager::keyPress(unsigned int keyID)
{
    _keyMap[keyID] = true;
}

void InputManager::keyRelease(unsigned int keyID)
{
    _keyMap[keyID] = false;
}

bool InputManager::isKeyPressed(unsigned int keyID)
{
    auto mit = _keyMap.find(keyID);
    if (mit == _keyMap.end()){
        return false;
    }
    else{
        return mit->second;
    }
}
