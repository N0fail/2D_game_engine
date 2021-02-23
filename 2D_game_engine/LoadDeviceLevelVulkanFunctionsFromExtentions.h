#ifndef LOADING_DEVICE_LEVEL_FUNCTIONS_FROM_EXTENTION
#define LOADING_DEVICE_LEVEL_FUNCTIONS_FROM_EXTENTION

#include "Common.h"

namespace VAPI {

	bool LoadDeviceLevelVulkanFunctionsFromExtentions(VkDevice, std::vector<char const*> const&);

} // namespace VAPI

#endif // LOADING_DEVICE_LEVEL_FUNCTIONS_FROM_EXTENTION

