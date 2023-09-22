#pragma once
#include "R2R_Vulkan_Instance.h"
#include "R2R_Vulkan_Device.h"
#include "R2R_AppDataTypes.h"
#include <vulkan/vulkan.h>
#include "R2R_Layer_Utils.h"
namespace R2R{
    class R2R_Vulkan_Engine{
        public:
        R2R_Vulkan_Engine();
        R2R_Vulkan_Engine(const R2R_Vulkan_Engine & app);
        ~R2R_Vulkan_Engine();

        void configure_init();
        void init_systems();
        private:
        InitInfo _init;
        Vulkan_Application _app;
    };
}