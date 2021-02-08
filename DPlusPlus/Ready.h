#pragma once

#include <vector>
#include <nlohmann/json.hpp>

#include "User.h"
#include "Guild.h"
#include "Channel.h"

using nJson = nlohmann::json;

class Ready {

public:
	int gVersion;
	std::string session_id;
	User user;
	vector<Unavailable_Guild> unavailableGuilds;
	vector<Channel> privateChannels;

public:
	Ready() {}
	Ready(const nJson &data);

};

