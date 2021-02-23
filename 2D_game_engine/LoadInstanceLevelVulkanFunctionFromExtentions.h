#ifndef LOADING_INSTANCE_LEVEL_FUNCTIONS_FROM_EXTENTION
#define LOADING_INSTANCE_LEVEL_FUNCTIONS_FROM_EXTENTION

#include "Common.h"

namespace VAPI {

	bool LoadInstanceLevelVulkanFunctionFromExtentions(VkInstance, std::vector<char const*> const&);

} // namespace VAPI

#endif // LOADING_INSTANCE_LEVEL_FUNCTIONS_FROM_EXTENTION

