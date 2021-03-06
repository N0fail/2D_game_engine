#ifndef VULKAN_FUNCTIONS
#define VULKAN_FUNCTIONS
#include "vulkan.h"
#include "vk_platform.h"
namespace VAPI {
	#define EXPORTED_VULKAN_FUNCTION( name ) extern PFN_##name name;
	#define GLOBAL_LEVEL_VULKAN_FUNCTION( name ) extern PFN_##name name;
	#define INSTANCE_LEVEL_VULKAN_FUNCTION( name ) extern PFN_##name name;
	#define INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( name,extension) extern PFN_##name name;
	#define DEVICE_LEVEL_VULKAN_FUNCTION( name ) extern PFN_##name name;
	#define DEVICE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( name,extension) extern PFN_##name name;
	#include "ListOfVulkanFunctions.inl"
} 
#endif // VULKAN_FUNCTIONS