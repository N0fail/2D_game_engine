#ifndef CREATING_VK_INSTANCE_WITH_EXTENTIONS
#define CREATING_VK_INSTANCE_WITH_EXTENTIONS

#include "Common.h"

namespace VAPI {

	bool CreateVkInstanceWithExtentions(VkInstance&, std::vector<const char*>&, const char*);

} // namespace VAPI

#endif // CREATING_VK_INSTANCE_WITH_EXTENTIONS
