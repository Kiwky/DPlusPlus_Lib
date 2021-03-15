#pragma once

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

#include "Utilities.h"
#include "User.h"
#include "Snowflake.h"

using nJson = nlohmann::json;
using namespace DPlusPlus::Template;

enum Message_Type {
	DEFAULT = 0,
	RECIPIENT_ADD,
	RECIPIENT_REMOVE,
	CALL,
	CHANNEL_NAME_CHANGE,
	CHANNEL_ICON_CHANGE,
	CHANNEL_PINNED_MESSAGE,
	GUILD_MEMBER_JOIN,
	USER_PREMIUM_GUILD_SUBSCRIPTION,
	USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_1,
	USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_2,
	USER_PREMIUM_GUILD_SUBSCRIPTION_TIER_3,
	CHANNEL_FOLLOW_ADD,
	GUILD_DISCOVERY_DISQUALIFIED,
	GUILD_DISCOVERY_REQUALIFIED,
	REPLY,
	APPLICATION_COMMAND,
};

class Message {

public:
	Snowflake id;
	Snowflake channel_id;
	Snowflake guild_id;
	Snowflake webhook_id;
	int flags;
	Message_Type type;
	User author;							
	//Member member;						
	std::string content;
	std::string timestamp;
	std::string edited_timestamp;
	bool tts = false;
	bool mention_everyone = false;
	bool pinned = false;
	std::vector<User> mentions;			
	//std::vector<Role> mention_roles;		
	//std::vector<Attachments> attachments;
	//std::vector<Embed> embeds;			
	//std::vector<Reaction> reactions;		

public:
	Message() {}
	Message(const nJson &data);

public:
	// Serialize class without vectors.
	void ToJson(nJson &j);

};

class MessageDelete {

public:
	Snowflake id;
	Snowflake channel_id;
	Snowflake guild_id;

public:
	MessageDelete(const nJson &data);

};