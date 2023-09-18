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

        struct init_info{
            //window xywh
            //title
            //renderer
            //etc.
        };

        struct Vulkan_Application{
            //maybe make these arrays??
            R2R::Instance instance;
            R2R::PhysicalDevice physicalDevice;
            R2R::LogicalDevice logicalDevice;

            Window _window;
        };

        Vulkan_Application _app;
        //add validation layers
        //add physical and logical devices
        //queues
        //heaps
        //application
        //command pool
        //descriptor pool
        
    };
}