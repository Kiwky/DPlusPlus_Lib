#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include "Emoji.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

class GuildPreview {

public:
	Snowflake id;
	int approximate_presence_count;
	int approximate_member_count;
	std::string name;
	std::string icon;
	std::string splash;
	std::string discovery_splash;
	std::string description;
	std::vector<Emoji> emojis;
	//std::vector<Feature> features;

public:
	GuildPreview() {}
	GuildPreview(const nJson &data);

};

