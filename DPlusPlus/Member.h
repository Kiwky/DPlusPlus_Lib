#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include "User.h"

using nJson = nlohmann::json;

class Member {

public:
	User user;
	std::string nick;
	std::string joined_at;
	std::string premium_since;
	std::string permissions;
	std::vector<std::string> roles;
	bool deaf;
	bool mute;
	bool pending;

public:
	Member() {}
	Member(const nJson &data);

};

