#pragma once
#include "R2R_Vulkan_Instance.h"
#include "R2R_Vulkan_Device.h"
#include "../Window.h"
#include <vulkan/vulkan.h>

namespace R2R{
    class R2R_Vulkan{
        public:
        R2R_Vulkan();
        R2R_Vulkan(const R2R_Vulkan & app);
        ~R2R_Vulkan();

        
        void R2R_Vulkan_init_systems();
        //void init_systems()

        
        private:
        R2R::Instance _instance; //custom class
        R2R::PhysicalDevice _physicalDevice;
        
        //add validation layers
        //add physical and logical devices
        //queues
        //heaps
        //application
        //command pool
        //descriptor pool
        Window _window;
    };
}