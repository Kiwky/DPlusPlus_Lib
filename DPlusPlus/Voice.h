#pragma once

#include <string>
#include <nlohmann/json.hpp>

using nJson = nlohmann::json;

class Voice {

public:
	std::string guild_id;
	std::string channel_id;
	std::string user_id;
	std::string session_id;
	bool deaf;
	bool mute;
	bool self_deaf;
	bool self_mute;

public:
	Voice() {}
	Voice(const nJson &data);

};

