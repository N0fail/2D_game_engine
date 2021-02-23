#include "LoadDeviceLevelVulkanFunctionsFromExtentions.h"

namespace VAPI {
	bool LoadDeviceLevelVulkanFunctionsFromExtentions(VkDevice device,
		std::vector<char const*> const& enabled_extensions) {

#define DEVICE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( name, extension ) for( auto & enabled_extension : enabled_extensions ) { \
			if( std::string( enabled_extension ) == std::string( extension ) )\
			{ \
				name = (PFN_##name)vkGetDeviceProcAddr(device, #name); \
				if( name == nullptr ) { \
				std::cout << "Could not load device-level Vulkan function named: "\
					#name << std::endl; \
					return false; \
				} \
			} \
			{\
				std::cout << "Loaded device-level Vulkan extentionss function named: "\
					#name << std::endl; \
			}\
		}
#include "ListOfVulkanFunctions.inl"
		return true;
	}
}