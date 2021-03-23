#pragma once

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

#include "Utilities.h"
#include "Role.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

class User;

// TODO DESTRUCTOR
class Emoji {

public:
	Snowflake id;
	bool require_colons;
	bool managed;
	bool animated;
	bool available;
	std::string name;
	User *user = nullptr;
	std::vector<Role> roles;

public:
	Emoji() {}
	Emoji(const nJson &data);
};

