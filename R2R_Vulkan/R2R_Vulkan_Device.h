#pragma once
#include <vulkan/vulkan.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

namespace R2R{
    
class PhysicalDevice{
    public:
    PhysicalDevice();
    ~PhysicalDevice();
    private:
    VkPhysicalDevice _physicalDevice;
};

class LogicalDevice{
    public:
    LogicalDevice();
    ~LogicalDevice();
    private:
    VkDevice _logicalDevice;
};

}