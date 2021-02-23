#include "CreateVkInstanceWithExtentions.h"
#include "LoadInstanceExtentions.h"

namespace VAPI {

    bool CreateVkInstanceWithExtentions(VkInstance& instance, std::vector<const char*>& desired_extensions, const char* application_name) {
		std::vector<VkExtensionProperties> available_extensions;
		LoadInstanceExtentions(available_extensions);

		for (auto& extension : desired_extensions) {
			if (!IsExtensionSupported(available_extensions, extension)) {
				std::cout << "Extension named '" << extension << "' is not supported." << std::endl;
				return false;
			}
		}
		VkApplicationInfo application_info = {
			VK_STRUCTURE_TYPE_APPLICATION_INFO,
			nullptr,
			application_name,
			VK_MAKE_VERSION(1, 0, 0),
			"VAPI",
			VK_MAKE_VERSION(1, 0, 0),
			VK_MAKE_VERSION(1, 0, 0)
		};
		VkInstanceCreateInfo instance_create_info = {
			VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO,
			nullptr,
			0,
			&application_info,
			0,
			nullptr,
			desired_extensions.size(),
			desired_extensions.size() > 0 ? &desired_extensions[0] : nullptr
		};
		VkResult result = VK_SUCCESS;
		result = vkCreateInstance(&instance_create_info, nullptr, &instance);
		if (result != VK_SUCCESS) {
			std::cout << "Error occured performing vkCreateInstance in CreateVkInstanceWithExtentions" << std::endl;
			return false;
		}
        return true;
    }

}