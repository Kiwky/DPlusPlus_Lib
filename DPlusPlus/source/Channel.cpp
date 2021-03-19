#include "Channel.h"

// Get channel by id.
Channel::Channel(const Snowflake channel_id) {
	*this = Channel(API_Call("/channels/" + channel_id, methods::GET, ""));
}

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

std::vector<Message> Channel::GetMessages(int limit) {
	std::vector<Message> result;

	nJson jsonResult = API_Call(
		"/channels/" + id + "/messages?limit=" + std::to_string(limit),
		methods::GET,
		""
	);

	for(auto iter = jsonResult.begin(); iter != jsonResult.end(); ++iter) {
		result.emplace_back(Message(*iter));
	}

	return result;
}

Message Channel::GetMessage(const Snowflake &message_id) {
	return Message();
}

void Channel::SendMessage(const std::string &content, Embed *embed) {
	nJson object;
	Message message;

	message.content = content;
	if(embed != nullptr) {
		message.embeds = *embed;
	}

	message.ToJson(object);
	API_Call("/channels/" + this->id + "/messages", methods::POST, object.dump());
}