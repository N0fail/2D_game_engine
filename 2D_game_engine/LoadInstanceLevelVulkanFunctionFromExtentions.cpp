#include "LoadInstanceLevelVulkanFunctionFromExtentions.h"

namespace VAPI {
	bool LoadInstanceLevelVulkanFunctionFromExtentions(VkInstance					  instance,
													  std::vector<char const*> const& enabled_extensions) {
#define INSTANCE_LEVEL_VULKAN_FUNCTION_FROM_EXTENSION( name, extension ) for( auto & enabled_extension : enabled_extensions ) { \
			if( std::string( enabled_extension ) == std::string( extension ) )\
			{ \
				name = (PFN_##name)vkGetInstanceProcAddr(instance, #name); \
				if( name == nullptr ) { \
				std::cout << "Could not load instance-level Vulkan function named: "\
					#name << std::endl; \
					return false; \
				} \
			} \
			{\
				std::cout << "Loaded instance-level Vulkan extentionss function named: "\
					#name << std::endl; \
			}\
		}
#include "ListOfVulkanFunctions.inl"
		return true;
	}
}