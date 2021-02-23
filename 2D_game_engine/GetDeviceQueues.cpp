#include "GetDeviceQueues.h"
namespace VAPI {
	void GetDeviceQueues(VkDevice logical_device, std::vector<VkDeviceQueueCreateInfo> queue_create_infos, std::vector<VkQueue>& queues) {
		queues.resize(queue_create_infos.size());
		for (size_t queue_index = 0; queue_index < queue_create_infos.size(); queue_index++)
		{
			vkGetDeviceQueue(logical_device, queue_create_infos[queue_index].queueFamilyIndex, 0, &queues[queue_index]); // 3rd param can be different if we have numerous queues from the same family
		}
	}
} //VAPI