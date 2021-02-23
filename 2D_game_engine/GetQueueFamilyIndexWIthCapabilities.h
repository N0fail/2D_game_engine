#ifndef GETTING_QUEUE_FAMILY_WITH_CAPABILITIES
#define GETTING_QUEUE_FAMILY_WITH_CAPABILITIES
#include "Common.h"
namespace VAPI {
	bool GetQueueFamilyIndexWIthCapabilities(std::vector<VkQueueFamilyProperties>&, VkQueueFlags&, uint32_t&);
} // VAPI
#endif // GETTING_QUEUE_FAMILY_WITH_CAPABILITIES