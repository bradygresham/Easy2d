#pragma once
#include "R2R_Vulkan_Instance.h"
#include "../Window.h"
#include <vulkan/vulkan.h>

namespace R2R{
    class VK{
        public:
        VK();
        VK(const VK & app);
        ~VK();

        void VK_init_systems();
        //void init_systems()


        private:
        R2R::Instance _instance; //custom class
        Window _window;
    };
}