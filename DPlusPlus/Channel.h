#pragma once

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

#include "User.h"

using nJson = nlohmann::json;

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
	int position;
	int bitrate;
	int user_limit;
	int rate_limit_per_user;
	bool nsfw;
	std::string id;
	std::string guild_id;
	std::string parent_id;
	std::string name;
	std::string topic;
	std::string icon;
	Channel_Type type;
	//vector<Overwrite> permission_overwrites;

public:
	Channel() {}
	Channel(const nJson &data);

};

