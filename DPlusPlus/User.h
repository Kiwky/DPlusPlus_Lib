#pragma once

#include <string>
#include <nlohmann/json.hpp>

using namespace std;
using nJson = nlohmann::json;

class User {

public:
	int flags;
	int premium_type;
	int public_flags;
	bool bot = false;
	bool system = false;
	bool mfa_enabled = false;
	bool verified = false;
	std::string username;
	std::string discriminator;
	std::string avatar;
	std::string email;
	std::string locale;

public:
	User() {}
	User(const nJson &data);

};

