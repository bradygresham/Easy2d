#include "R2R_Vulkan.h"

R2R::R2R_Vulkan::R2R_Vulkan():
_app{
    R2R::Instance{},
    R2R::PhysicalDevice{},
    R2R::LogicalDevice{},
    Window{}
}
{
}

R2R::R2R_Vulkan::R2R_Vulkan(const R2R_Vulkan &app)
{
}

R2R::R2R_Vulkan::~R2R_Vulkan()
{
}

void R2R::R2R_Vulkan::R2R_Vulkan_init_systems()
{
    _app.instance.init_instance(_app._window.getWindow());
}
