#pragma once

#include <string>
#include <memory>
#include <nlohmann/json.hpp>

#include "Utilities.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

class Member;

// TODO DESTRUCTOR
class Voice {

public:
	Snowflake guild_id;
	Snowflake channel_id;
	Snowflake user_id;
	bool deaf;
	bool mute;
	bool self_deaf;
	bool self_mute;
	bool self_stream;
	bool self_video;
	bool supress;
	std::string session_id;
	Member *member = nullptr;

public:
	Voice() {}
	Voice(const nJson &data);

};

