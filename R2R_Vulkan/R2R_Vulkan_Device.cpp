#include "R2R_Vulkan_Device.h"
#include "../Error.h"
namespace R2R
{
    //Physical Device Methods

    PhysicalDevice::PhysicalDevice(){
        _physicalDevice = NULL;
    }
    PhysicalDevice::PhysicalDevice(const VkInstance &instance)
    {
        _physicalDevice = NULL;
        VkInstance tmpInst = instance;
        init_device(tmpInst);
    }
    PhysicalDevice::~PhysicalDevice()
    {
    }

    void PhysicalDevice::init_device(const VkInstance &instance){
        VkResult result = VK_SUCCESS;
        uint32_t deviceCount = 0;

        result = vkEnumeratePhysicalDevices( instance,&deviceCount, (VkPhysicalDevice *)nullptr ); 

        if( result != VK_SUCCESS || deviceCount <= 0 ){
            error("Could not count the physical devices");
        }

        VkPhysicalDevice * physicalDevices = new VkPhysicalDevice[ deviceCount ];
	    result = vkEnumeratePhysicalDevices( instance, &deviceCount, physicalDevices  );
	
        int discreteSelect   = -1;
	    int integratedSelect = -1;

        for( unsigned int i = 0; i < deviceCount; i++ ){
            VkPhysicalDeviceProperties vpdp;
		    vkGetPhysicalDeviceProperties( physicalDevices[i], &vpdp );

            if( vpdp.deviceType == VK_PHYSICAL_DEVICE_TYPE_DISCRETE_GPU ){
			    discreteSelect = i;
            }
		    if( vpdp.deviceType == VK_PHYSICAL_DEVICE_TYPE_INTEGRATED_GPU ){
			    integratedSelect = i;
            }
        }
        int which = -1;
        if( discreteSelect >= 0 )
        {
            which = discreteSelect;
            _physicalDevice = physicalDevices[which];
        }
        else if( integratedSelect >= 0 )
        {
            which = integratedSelect;
            _physicalDevice = physicalDevices[which];
        }
        else
        {
            error("Could not select a physical device");
        }
    }

    VkPhysicalDevice* PhysicalDevice::getPtr(){
        return &_physicalDevice;
    }
    
    //Logical Device Methods

    LogicalDevice::LogicalDevice(){

    }
    LogicalDevice::~LogicalDevice(){
        
    }
}
