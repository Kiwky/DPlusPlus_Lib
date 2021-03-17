#include "Channel.h"

Channel::Channel(const nJson &data) {
	GetJson(data, "id",					/**/ id);
	GetJson(data, "guild_id",			/**/ guild_id);
	GetJson(data, "last_message_id",	/**/ last_message_id);
	GetJson(data, "position",			/**/ position);
	GetJson(data, "bitrate",			/**/ bitrate);
	GetJson(data, "user_limit",			/**/ user_limit);
	GetJson(data, "type",				/**/ type);
	GetJson(data, "name",				/**/ name);
	GetJson(data, "topic",				/**/ topic);
	GetJson(data, "icon",				/**/ icon);
	GetJson(data, "nsfw",				/**/ nsfw);
}
