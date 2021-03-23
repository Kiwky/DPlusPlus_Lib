#pragma once

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

#include "Utilities.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

class User;

class Member {

public:
	std::unique_ptr<User> user;
	bool deaf;
	bool mute;
	bool pending;
	std::string nick;
	std::string joined_at;
	std::string premium_since;
	std::string permissions;
	//std::vector<Role> roles;

public:
	Member() {}
	Member(const nJson &data);

};

