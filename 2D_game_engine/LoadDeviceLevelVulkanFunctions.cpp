#include "LoadDeviceLevelVulkanFunctions.h"

namespace VAPI {
    bool LoadDeviceLevelVulkanFunctions(VkDevice device ) {
        // Load core Vulkan API instance-level functions
#define DEVICE_LEVEL_VULKAN_FUNCTION( name )                                  \
        name = (PFN_##name)vkGetDeviceProcAddr( device, #name );                \
        if( name == nullptr ) {                                                     \
          std::cout << "Could not load device-level Vulkan function named: "      \
            #name << std::endl;                                                     \
          return false;                                                             \
        }                                                                           
#include "ListOfVulkanFunctions.inl"
        return true;
    }
}