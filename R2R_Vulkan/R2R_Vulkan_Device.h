#pragma once
#include <vulkan/vulkan.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

namespace R2R{
    
class PhysicalDevice{
    public:
    PhysicalDevice();
    PhysicalDevice(VkInstance &instance);
    ~PhysicalDevice();

    void init_device(VkInstance &instance);
    VkPhysicalDevice * getPtr();

    private:
    VkPhysicalDevice _physicalDevice;
};

class LogicalDevice{
    public:
    LogicalDevice();
    ~LogicalDevice();

    void init_device();
    private:
    VkDevice _logicalDevice;
};

}