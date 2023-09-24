#pragma once
#include <cstdint>
#include <vulkan/vulkan.h>
extern bool instance_check_layer_availability(const char * instanceLayersWanted[ ]);
extern bool device_check_layer_availability(const char * deviceLayersWanted[ ],const VkPhysicalDevice &physicalDevice);