#include "Channel.h"
#include "Utilities.h"

Channel::Channel(const nJson &data) {
	DPlusPlus::Template::GetJson(data, "position",				/**/ this->position);
	DPlusPlus::Template::GetJson(data, "bitrate",				/**/ this->bitrate);
	DPlusPlus::Template::GetJson(data, "user_limit",			/**/ this->user_limit);
	DPlusPlus::Template::GetJson(data, "rate_limit_per_user",	/**/ this->rate_limit_per_user);
	DPlusPlus::Template::GetJson(data, "nsfw",					/**/ this->nsfw);
	DPlusPlus::Template::GetJson(data, "id",					/**/ this->id);
	DPlusPlus::Template::GetJson(data, "guild_id",				/**/ this->guild_id);
	DPlusPlus::Template::GetJson(data, "parent_id",				/**/ this->parent_id);
	DPlusPlus::Template::GetJson(data, "name",					/**/ this->name);
	DPlusPlus::Template::GetJson(data, "topic",					/**/ this->topic);
	DPlusPlus::Template::GetJson(data, "icon",					/**/ this->icon);
	DPlusPlus::Template::GetJson(data, "type",					/**/ this->type);
}