#include "R2R_Layer_Utils.h"
#include "../Error.h"
#include <cstring>
#include <vulkan/vulkan.h>

bool instance_check_layer_availability(const char *instanceLayersWanted[])
{
    uint32_t numLayersWanted = sizeof(instanceLayersWanted) / sizeof(char *);

        uint32_t numLayersAvailable;
		vkEnumerateInstanceLayerProperties( &numLayersAvailable, (VkLayerProperties *)nullptr);
		VkLayerProperties* InstanceLayers = new VkLayerProperties[ numLayersAvailable ];
		VkResult result = vkEnumerateInstanceLayerProperties( &numLayersAvailable, InstanceLayers );
		if( result != VK_SUCCESS )
		{
			error("Layers not init");
		}

		for( uint32_t wanted = 0; wanted < numLayersWanted; wanted++ )
		{
            bool is_available = false;
			for( uint32_t available = 0; available < numLayersAvailable; available++ )
			{
				if( strcmp( instanceLayersWanted[wanted], InstanceLayers[available].layerName ) == 0 )
				{
					is_available = true;
					break;
				}
			}
            if(!is_available){
                return false;
            }
		}

        delete [] InstanceLayers;
        return true;
}