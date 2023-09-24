#pragma once
#include <vulkan/vulkan.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_vulkan.h>

namespace R2R{
    
class PhysicalDevice{
    public:
    PhysicalDevice();
    PhysicalDevice(const VkInstance &instance);
    ~PhysicalDevice();

    void init_device(const VkInstance &instance);
    VkPhysicalDevice  getDevice();

    private:
    VkPhysicalDevice _physicalDevice;
};

class LogicalDevice{
    public:
    LogicalDevice();
    ~LogicalDevice();

    void init_device(const VkPhysicalDevice &physicalDevice);
    private:
    VkDevice _logicalDevice;
};

}