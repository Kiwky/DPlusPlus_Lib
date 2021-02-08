#include "Message.h"
#include "Utilities.h"

Message::Message(const nJson &data) {
	this->author = User(data["author"]);

	DPlusPlus::Template::GetJson(data, "type",				/**/ this->type);
	DPlusPlus::Template::GetJson(data, "id",				/**/ this->id);
	DPlusPlus::Template::GetJson(data, "channel_id",		/**/ this->channel_id);
	DPlusPlus::Template::GetJson(data, "guild_id",			/**/ this->guild_id);
	DPlusPlus::Template::GetJson(data, "content",			/**/ this->content);
	DPlusPlus::Template::GetJson(data, "tts",				/**/ this->tts);
	DPlusPlus::Template::GetJson(data, "mention_everyone",	/**/ this->mention_everyone);
	DPlusPlus::Template::GetJson(data, "pinned",			/**/ this->pinned);
}
