#include "R2R_Vulkan.h"

R2R::R2R_Vulkan::R2R_Vulkan():
_app{
    Window{},
    Renderer{},
    R2R::Instance{},
    R2R::PhysicalDevice{},
    R2R::LogicalDevice{},
    Camera2D{},
    InputManager{}
}

{
}

R2R::R2R_Vulkan::R2R_Vulkan(InitInfo &info)
{
    init_systems(info);
}

R2R::R2R_Vulkan::R2R_Vulkan(const R2R_Vulkan &app)
{
}

R2R::R2R_Vulkan::~R2R_Vulkan()
{
}

void R2R::R2R_Vulkan::init_systems(InitInfo &info)
{
    //initialize info for creation
    _init = info;
    
    _app.window.init_window(_init.winfo);
    _app.renderer.init_renderer(_app.window.getWindow(),0);
    _app.instance.init_instance(_init.create,_init.app);
    _app.physicalDevice.init_device(_app.instance.getInstance());
    _app.camera2d.init_camera(_app.window.get_width(),_app.window.get_height());

    //init devices
}
