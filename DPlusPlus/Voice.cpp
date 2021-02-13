#include "Voice.h"
#include "Utilities.h"

Voice::Voice(const nJson &data) {
	DPlusPlus::Template::GetJson(data, "guild_id",		/**/ this->guild_id);
	DPlusPlus::Template::GetJson(data, "channel_id",	/**/ this->channel_id);
	DPlusPlus::Template::GetJson(data, "user_id",		/**/ this->user_id);
	DPlusPlus::Template::GetJson(data, "session_id",	/**/ this->session_id);
	DPlusPlus::Template::GetJson(data, "deaf",			/**/ this->deaf);
	DPlusPlus::Template::GetJson(data, "mute",			/**/ this->mute);
	DPlusPlus::Template::GetJson(data, "self_deaf",		/**/ this->self_deaf);
	DPlusPlus::Template::GetJson(data, "self_mute",		/**/ this->self_mute);
}