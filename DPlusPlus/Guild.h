#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include "Role.h"
#include "Voice.h"
#include "Member.h"
#include "Channel.h"

using nJson = nlohmann::json;

class Guild {

public:
	int afk_timeout;
	int verification_level;
	int default_message_notifications;
	int explicit_content_filter;
	int mfa_level;
	int system_channel_flags;
	int member_count;
	int max_presences;
	int max_members;
	int premium_tier;
	int premium_subscription_count;
	int max_video_channel_users;
	int approximate_member_count;
	int approximate_presence_count;
	std::string id;
	std::string name;
	std::string icon;
	std::string icon_hash;
	std::string spalsh;
	std::string discovery_splash;
	std::string owner_id;
	std::string permissions;
	std::string region;
	std::string afk_channel_id;
	std::string widget_channel_id;
	std::string application_id;
	std::string system_channel_id;
	std::string rules_channel_id;
	std::string vanity_url_code;
	std::string description;
	std::string banner;
	std::string public_updates_channel_id;
	std::string joined_at;
	bool owner;
	bool large;
	bool unavailable;
	std::vector<Role> roles;
	std::vector<Member> members;
	std::vector<Channel> channels;


public:
	Guild() {}
	Guild(const nJson &data);

};

class Unavailable_Guild {

public:
	std::string id;
	bool unavailable;

public:
	Unavailable_Guild() {}
	Unavailable_Guild(const nJson &data);

};