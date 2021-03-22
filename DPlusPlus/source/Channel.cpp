#include "Channel.h"

// Get channel by id.
Channel::Channel(const Snowflake channel_id) {
	*this = Channel(API_Call("/channels/" + channel_id, methods::GET));
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

void Channel::ToJson(nJson &j) {
	if(bitrate > 0)
		j["bitrate"] = bitrate;

	j = nJson{
		{ "id",				id				},
		{ "guild_id",		guild_id		},
		{ "last_message_id",last_message_id	},
		{ "position",		position		},
		{ "user_limit",		user_limit		},
		{ "type",			type			},
		{ "name",			name			},
		{ "topic",			topic			},
		{ "icon",			icon			},
		{ "nsfw",			nsfw			}
	};
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

Message Channel::GetMessage(const Snowflake &message_id) {
	return Message(API_Call("/channels/" + this->id + "/messages/" + message_id, methods::GET));
}

std::vector<Message> Channel::GetMessages(int limit) {
	std::vector<Message> result;

	nJson jsonResult = API_Call("/channels/" + id + "/messages?limit=" + std::to_string(limit), methods::GET);

	for(auto iter = jsonResult.begin(); iter != jsonResult.end(); ++iter) {
		result.emplace_back(Message(*iter));
	}

	return result;
}

Channel Channel::ModifyChannel(Channel &new_channel) {
	nJson object;
	new_channel.ToJson(object);

	API_Call("/channels/" + this->id, methods::PATCH, object.dump());

	// TODO
	return Channel();
}

Message Channel::ModifyMessage(const Snowflake &message_id, Message &new_message) {
	nJson object;
	new_message.ToJson(object);

	API_Call("/channels/" + this->id + "/messages/" + message_id, methods::PATCH, object.dump());

	// TODO
	return Message();
}

void Channel::ModifyChannelPermissions(/*const Overwrite overwrite*/) {

}

void Channel::DeleteChannelPermission(/*const Overwrite overwrite*/) {

}

void Channel::DeleteMessage(const Snowflake &message_id) {
	API_Call("/channels/" + this->id + "/messages/" + message_id, methods::DEL);
}

void Channel::DeleteMessageBulk(std::vector<Message> message_list) {
	nJson object;

	for(auto iter = message_list.begin(); iter != message_list.end(); ++iter) {
		object["messages"].push_back(iter->id);
	}

	API_Call("/channels/" + this->id + "/messages/bulk-delete", methods::POST, object.dump());
}

void Channel::DeleteChannel() {
	API_Call("/channels/" + this->id, methods::DEL);
}

void Channel::DeleteUserReaction(const Snowflake &message_id, const std::string &emoji) {

}

void Channel::DeleteAllReactions(const Snowflake &message_id) {
	API_Call("/channels/" + this->id + "/messages/" + message_id + "/reactions", methods::DEL);
}

void Channel::CreateReaction(const Snowflake &message_id, const std::string &emoji) {
	API_Call("/channels/" + this->id + "/messages/" + message_id + "/reactions/" + emoji + "/@me", methods::PUT);
}

std::vector<User> Channel::GetReactions(const Snowflake &message_id, const std::string &emoji) {
	return std::vector<User>();
}

std::vector<Invite> Channel::GetInvites() {
	std::vector<Invite> result;

	nJson jsonResult = API_Call("/channels/" + this->id + "/invites", methods::GET);

	for(auto iter = jsonResult.begin(); iter != jsonResult.end(); ++iter) {
		result.emplace_back(Invite(*iter));
	}

	return result;
}

Invite Channel::CreateInvite(int max_age, int max_uses, bool temporary, const std::string &target_user /*= ""*/) {
	return Invite();
}

std::vector<Message> Channel::GetPinnedMessages() {
	return std::vector<Message>();
}

void Channel::AddPinnedMessage(const Snowflake &message_id) {

}

void Channel::DeletePinnedMessage(const Snowflake &message_id) {

}
