#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Utilities.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

class Role {

public:
	Snowflake id;
	int position;
	int color;
	bool hoist;
	bool managed;
	bool mentionable;
	std::string permissions;
	std::string name;

public:
	Role() {}
	Role(const nJson &data);

};

