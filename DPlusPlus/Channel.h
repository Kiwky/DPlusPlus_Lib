#pragma once

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

#include "User.h"

using nJson = nlohmann::json;

class Channel {

public:
	int type;
	int position;
	int bitrate;
	int user_limit;
	int rate_limit_per_user;
	bool nsfw;
	std::string id;
	std::string guildId;
	std::string name;
	std::string topic;
	std::string icon;
	vector<User> recipients;
	//vector<Overwrite> permission_overwrites;

public:
	Channel() {}
	Channel(const nJson &data);

};

