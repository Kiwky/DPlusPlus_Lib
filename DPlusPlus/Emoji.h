#pragma once

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

#include "User.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

class Emoji {

public:
	Snowflake id;
	bool require_colons;
	bool managed;
	bool animated;
	bool available;
	std::string name;
	User user;
	//std::vector<Role> roles;

public:
	Emoji() {}
	Emoji(const nJson &data);

};

