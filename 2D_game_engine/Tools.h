#ifndef VAPI_TOOLS
#define VAPI_TOOLS
#include "Common.h"
namespace VAPI {
	struct QueueInfo {
		uint32_t family_index;
		std::vector<float> priorities;
		QueueInfo(uint32_t, std::initializer_list<float>);
	};
}
#endif // ! VAPI_TOOLS

