#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include "User.h"
#include "Channel.h"
#include "Guild.h"

using nJson = nlohmann::json;

enum Message_Type {
	DEFAULT = 0,
	RECIPIENT_ADD,
	RECIPIENT_REMOVE,
	CALL,
	CHANNEL_NAME_CHANGE,
	CHANNEL_ICON_CHANGE,
	CHANNEL_PINNED_MESSAGE,
	GUILD_MEMBER_JOIN,
	USER_PREMIUM_GUILD_SUBSCRIPTION,
	USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1,
	USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2,
	USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3,
	CHANNEL_FOLLOW_ADD,
	GUILD_DISCOVERY_DISQUALIFIED,
	GUILD_DISCOVERY_REQUALIFIED,
	REPLY,
	APPLICATION_COMMAND,
};


class Message {

public:
	User author;
	int type;
	std::string id;
	std::string channel_id;
	std::string guild_id;
	std::string content;
	bool tts = false;
	bool mention_everyone = false;
	bool pinned = false;

public:
	Message() {}
	Message(const nJson &data);

};


class MessageDeleteArg {

public:
	std::string id;
	std::string channe_id;
	std::string guild_id;

public:
	MessageDeleteArg(const nJson &data) {
		Message m(data);

		id = m.id;
		channe_id = m.channel_id;
		guild_id = m.guild_id;
	}

};
