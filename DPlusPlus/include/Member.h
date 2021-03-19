#pragma once

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

#include "Utilities.h"
#include "User.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

class Member {

public:
	User user;
	std::string nick;
	std::string joined_at;
	std::string premium_since;
	std::string permissions;
	bool deaf;
	bool mute;
	bool pending;
	//std::vector<Role> roles;

public:
	Member() {}
	Member(const nJson &data);

};

