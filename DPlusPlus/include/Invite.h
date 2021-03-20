#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Utilities.h"
#include "User.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

class Channel;	// Forward dec.

enum Target_User_Type {
	STREAM = 1
};

class Invite {

public:
	std::string code;
	// Guild guild;
	std::unique_ptr<Channel> channel;
	User inviter;

public:
	Invite() {}
	Invite(const nJson &data);
};

