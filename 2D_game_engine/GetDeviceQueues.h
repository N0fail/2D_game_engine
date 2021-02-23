#ifndef GETTING_DEVICE_QUEUES
#define GETTING_DEVICE_QUEUES
#include "Common.h"
#include "Tools.h"
namespace VAPI {
	void GetDeviceQueues(VkDevice, std::vector<VkDeviceQueueCreateInfo>, std::vector<VkQueue>&);
}
#endif // !GETTING_DEVICE_QUEUES

