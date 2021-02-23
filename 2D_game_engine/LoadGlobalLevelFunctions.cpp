#include "LoadGlobalLevelFunctions.h"

namespace VAPI {
    bool LoadGlobalLevelFunctions() {
#define GLOBAL_LEVEL_VULKAN_FUNCTION( name )                              \
    name = (PFN_##name)vkGetInstanceProcAddr( nullptr, #name );           \
    if( name == nullptr ) {                                               \
      std::cout << "Could not load global level Vulkan function named: "  \
        #name << std::endl;                                               \
      return false;                                                       \
    }                                                                     \
    {                                                                     \
        std::cout << "Loaded global Vulkan function named: "              \
        #name << std::endl;                                               \
    }

#include "ListOfVulkanFunctions.inl"

        return true;
    }
}