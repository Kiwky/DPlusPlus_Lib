#include "VoiceRegion.h"

VoiceRegion::VoiceRegion(const nJson &data) {
	GetJson(data, "id",			/**/ id);
	GetJson(data, "name",		/**/ name);
	GetJson(data, "vip",		/**/ vip);
	GetJson(data, "optimal",	/**/ optimal);
	GetJson(data, "deprecated", /**/ deprecated);
	GetJson(data, "custom",		/**/ custom);
}
