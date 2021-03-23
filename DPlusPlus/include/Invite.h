#pragma once

#include <string>
#include <memory>
#include <nlohmann/json.hpp>

#include "Utilities.h"
#include "User.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

class Channel;
class Guild;

enum Target_User_Type {
	STREAM = 1
};

class Invite {

public:
	std::string code;
	std::shared_ptr<Channel> channel;
	std::shared_ptr<Guild> guild;
	User inviter;

public:
	Invite() {}
	Invite(const Snowflake &invite_id);
	Invite(const nJson &data);

public:
	// TODO
	// Delete an invite. 
	// Requires the MANAGE_CHANNELS permission on the channel.
	// Requires the MANAGE_GUILD to remove any invite across the guild.
	void Delete();
};

