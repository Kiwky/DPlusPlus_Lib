#pragma once

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

#include "Utilities.h"
#include "Message.h"
#include "Embed.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

enum Channel_Type {
	GUILD_TEXT = 0,
	DM,
	GUILD_VOICE,
	GROUP_DM,
	GUILD_CATEGORY,
	GUILD_NEWS,
	GUILD_STORE
};

class Channel {

public:
	Snowflake id;
	Snowflake guild_id;
	Snowflake last_message_id;
	int position;
	int bitrate;
	int user_limit;
	Channel_Type type;
	std::string name;
	std::string topic;
	std::string icon;
	bool nsfw;
	// vector<overwrite> permission_overwrites;

public:
	Channel() {}
	Channel(const Snowflake channel_id);
	Channel(const nJson &data);

public:
	void SendMessage(const std::string &content, Embed *embed = nullptr);
	std::vector<Message> GetMessages(int _count);

};
