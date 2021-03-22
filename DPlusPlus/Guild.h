#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include "Utilities.h"
#include "Member.h"
#include "Channel.h"
#include "Emoji.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

class Guild {

public:
	Snowflake id;
	Snowflake owner_id;
	Snowflake afk_channel_id;
	Snowflake widget_channel_id;
	Snowflake application_id;
	Snowflake system_channel_id;
	Snowflake rules_channel_id;
	Snowflake public_updates_channel_id;
	int afk_timeout;
	int verification_level;
	int default_message_notifications;
	int expliciti_content_filter;
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
	bool owner;
	bool widget_enabled;
	bool large;
	bool unavailable;
	std::string name;
	std::string icon;
	std::string icon_hash;
	std::string splash;
	std::string discovery_splash;
	std::string permissions;
	std::string regions;
	std::string joined_at;
	std::string vanity_url_code;
	std::string description;
	std::string banner;
	std::string preferred_locale;
	std::vector<Channel> channels;
	std::vector<Member> members;
	std::vector<Emoji> emojis;
	// WelcomeScreen welcome_screen;
	//std::vector<VoiceState> voice_states;
	//std::vector<Role> roles;
	//std::vector<Feature> features;

public:
	Guild() {}
	Guild(const nJson &data);

};

