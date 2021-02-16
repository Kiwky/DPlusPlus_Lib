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
	bool deaf;
	bool mute;
	bool pending;
	std::vector<std::string> roles;

public:
	Member() {}
	Member(const nJson &data);

};

