#pragma once
#include "R2R_Vulkan_Instance.h"
#include "R2R_Vulkan_Device.h"
#include "../Window.h"
#include "R2R_App_Info.h"
#include <vulkan/vulkan.h>

namespace R2R{
    class R2R_Vulkan{
        public:
        R2R_Vulkan();
        R2R_Vulkan(InitInfo info);
        R2R_Vulkan(const R2R_Vulkan & app);
        ~R2R_Vulkan();

        void init_systems();
        private:
        InitInfo _init;
        Vulkan_Application _app;
    };
}