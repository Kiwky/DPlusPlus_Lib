#include "Message.h"

Message::Message(const nJson &data) {
	if(data.contains("author"))
		this->author = User(data["author"]);

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
}

void Message::ToJson(nJson &j) {
	j = nJson{
		{ "id",					(std::string)id			},
		{ "guild_id",			(std::string)guild_id	},
		{ "channel_id",			(std::string)channel_id	},
		{ "webhook_id",			(std::string)webhook_id	},
		{ "flags",				flags					},
		{ "type",				type					},
		{ "content",			content					},
		{ "timestamp",			timestamp				},
		{ "edited_timestamp",	edited_timestamp		},
		{ "tts",				tts						},
		{ "mention_everyone",	mention_everyone		},
		{ "pinned",				pinned					}
	};
}

MessageDelete::MessageDelete(const nJson &data) {
	Message m(data);

	id = m.id;
	channel_id = m.channel_id;
	guild_id = m.guild_id;
}
