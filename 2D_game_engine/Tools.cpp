#include "Tools.h"
namespace VAPI {
	QueueInfo::QueueInfo(uint32_t _family_index, std::initializer_list<float> _priorities) : family_index(_family_index), priorities(_priorities) {}
}