#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include "GuildPreview.h"
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
	Guild(const Snowflake &guild_id);
	Guild(const nJson &data);

public:
	void ToJson(nJson &j);

	// TODO
	// Returns a list of emoji objects for the given guild.
	std::vector<Emoji> ListEmoji();

	// TODO
	// Returns an emoji object for the given guild and emoji IDs.
	Emoji GetEmoji(const std::string &emoji_id);

	// TODO
	// Create a new emoji for the guild.
	// Requires the MANAGE_EMOJIS permission.
	Emoji CreateEmoji(const std::string &name, /*Image image*/ std::vector<Snowflake> *roles = nullptr);

	// TODO
	// Modify the given emoji. 
	// Requires the MANAGE_EMOJIS permission.
	Emoji ModifyEmoji(const std::string &name, std::vector<Snowflake> *roles = nullptr);

	// TODO
	// Delete the given emoji. 
	// Requires the MANAGE_EMOJIS permission. 
	void DeleteEmoji(const std::string &emoji_id);

	// TODO
	// Returns the guild preview object for the given id. 
	// If the user is not in the guild, then the guild must be Discoverable.
	GuildPreview GetGuildPreview();

	// TODO
	// Modify a guild's settings.
	// Requires the MANAGE_GUILD permission.
	Guild ModifyGuild(
		const std::string &name, const std::string &region,
		int verification_level, int default_message_notifications, int explicit_content_filter, int afk_timeout,
		const Snowflake &afk_channel_id
		/*,Image splash, Image banner*/
	);

	// TODO
	// Delete a guild permanently. 
	// User must be owner.
	void DeleteGuild();

	// TODO
	// Returns a list of guild channel objects.
	std::vector<Channel> GetChannels();

	// TODO
	// Create a new channel object for the guild. 
	// Requires the MANAGE_CHANNELS permission.
	Channel CreateChannel(/*Lista parametrii*/);

	// TODO
	// Modify the positions of a set of channel objects for the guild. 
	// Requires MANAGE_CHANNELS permission.
	void ModifyChannel(const Snowflake &channel_id, int new_position);

	// TODO
	// Returns a guild member object for the specified user.
	Member GetMember(const Snowflake &user_id);

	// TODO
	// Returns a list of guild member objects that are members of the guild.
	std::vector<Member> GetMembers();
};

