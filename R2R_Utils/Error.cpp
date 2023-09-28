#include "Error.h"
#include <SDL2/SDL.h>
#include <iostream>

void error(std::string message) {
    std::cout << message << std::endl;
    std::cout << "Press any key to continue...\n";
    int quit;
    std::cin >> quit;
    
}

void errorAndFilePath(std::string message, const char* filePath)
{
    std::cout << "File: " << filePath << std::endl;
    std::cout << message << std::endl;
    std::cout << "Press any key to continue...\n";
    int quit;
    std::cin >> quit;
    
}