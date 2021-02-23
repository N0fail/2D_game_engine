#include "LoadInstanceLevelVulkanFunctions.h"

namespace VAPI {
	bool LoadInstanceLevelVulkanFunctions(VkInstance instance) {
        // Load core Vulkan API instance-level functions
#define INSTANCE_LEVEL_VULKAN_FUNCTION( name )                                  \
        name = (PFN_##name)vkGetInstanceProcAddr( instance, #name );                \
        if( name == nullptr ) {                                                     \
          std::cout << "Could not load instance-level Vulkan function named: "      \
            #name << std::endl;                                                     \
          return false;                                                             \
        }                                                                           
    #include "ListOfVulkanFunctions.inl"
		 return true;
	}
}