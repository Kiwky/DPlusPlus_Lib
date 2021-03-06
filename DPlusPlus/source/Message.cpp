#include "Message.h"
#include "Channel.h"

Message::Message(const nJson &data) {
	if(data.contains("author"))
		author = User(data["author"]);

	GetJson(data, "id",					/**/ id);
	GetJson(data, "channel_id",			/**/ channel_id);
	GetJson(data, "guild_id",			/**/ guild_id);
	GetJson(data, "webhook_id",			/**/ webhook_id);
	GetJson(data, "flags",				/**/ flags);
	GetJson(data, "type",				/**/ type);
	GetJson(data, "content",			/**/ content);
	GetJson(data, "timestamp",			/**/ timestamp);
	GetJson(data, "edited_timestamp",	/**/ edited_timestamp);
	GetJson(data, "tts",				/**/ tts);
	GetJson(data, "mention_everyone",	/**/ mention_everyone);
	GetJson(data, "pinned",				/**/ pinned);

	GetJsonVector(data, "mentions",		/**/ mentions);

	channel = new Channel(channel_id);
}

void Message::ToJson(nJson &j) {
	nJson embedJson;
	if(embeds.description.length() > 0 || embeds.fields.size() > 0)
		embeds.ToJson(embedJson);

	j = nJson{
		{"content",	content		},
		{"embed",	embedJson	},
	};
}

MessageDelete::MessageDelete(const nJson &data) {
	GetJson(data, "id",					/**/ id);
	GetJson(data, "channel_id",			/**/ channel_id);
	GetJson(data, "guild_id",			/**/ guild_id);
}

MessageDeleteBulk::MessageDeleteBulk(const nJson &data) {
	GetJson(data, "channel_id",			/**/ channel_id);
	GetJson(data, "guild_id",			/**/ guild_id);

	GetJsonVector(data, "ids",			/**/ id);
}
