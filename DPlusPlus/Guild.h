#pragma once

#include <string>
#include <vector>
#include <nlohmann/json.hpp>

#include "GuildPreview.h"
#include "Utilities.h"
#include "Member.h"
#include "Channel.h"
#include "Emoji.h"
#include "VoiceRegion.h"

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
	//WelcomeScreen welcome_screen;			TODO
	//std::vector<VoiceState> voice_states; TODO
	//std::vector<Role> roles;				TODO
	//std::vector<Feature> features;		TODO

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
	Emoji GetEmoji(const Snowflake &emoji_id);

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
	void DeleteEmoji(const Snowflake &emoji_id);

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
	// Requires the MANAGE_CHANNELS permission.
	void ModifyChannel(const Snowflake &channel_id, int new_position);

	// TODO
	// Returns a guild member object for the specified user.
	Member GetMember(const Snowflake &user_id);

	// TODO
	// Returns a list of guild member objects that are members of the guild.
	std::vector<Member> GetMembers();

	// TODO
	// Modify attributes of a guild member.
	// Requires permission.
	// nick			= MANAGE_NICKNAMES
	// roles		= MANAGE_ROLES
	// mute			= MUTE_MEMBERS 
	// deaf			= DEAFEN_MEMBERS
	// channel_id	= MOVE_MEMBERS
	Member ModifyMember(const Snowflake &user_id, const std::string &new_nick, std::vector<Snowflake> roles, bool mute, bool deaf, const Snowflake &channel_id);

	// TODO
	// Modifies the nickname of the current user in a guild.
	// Requires the MANAGE_NICKNAMES permission.
	void ModifyMemberNickname(const Snowflake &user_id, const std::string &new_nick);

	// TODO
	// Adds a role to a guild member.
	// Requires the MANAGE_ROLES permission.
	void AddMemberRole(const Snowflake &user_id, const Snowflake &role_id);

	// TODO
	// Removes a role from a guild member.
	// Requires the MANAGE_ROLES permission.
	void RemoveMemberRole(const Snowflake &user_id, const Snowflake &role_id);

	// TODO
	// Remove a member from a guild.
	// Requires KICK_MEMBERS permission.
	void RemoveMemberRole(const Snowflake &user_id);

	// TODO
	// Returns a list of ban objects for the users banned from this guild.
	// Requires the BAN_MEMBERS permission.
	// std::vector<Ban> GetGuildBans();

	// TODO
	// Returns a ban object for the given user.
	// Requires the BAN_MEMBERS permission.
	// Ban GetGuildBan(const Snowflake &user_id);

	// TODO
	// Create a guild ban, and optionally delete previous messages sent by the banned user.
	// Requires the BAN_MEMBERS permission. 
	void Ban(const Snowflake &user_id, const std::string reason = "", int delete_message_days = 0);

	// TODO
	// Remove the ban for a user. 
	// Requires the BAN_MEMBERS permissions.
	void RemoveBan(const Snowflake &user_id);

	// TODO 
	// Returns a list of role objects for the guild.
	// std::vector<Role> GetRoles();

	// TODO
	// Create a new role for the guild.
	// Requires the MANAGE_ROLES permission. 
	// Role CreateRole(const std::string &name, const std::string permissions, int color, bool hoist, bool mentionable);

	// TODO
	// Modify the positions of a set of role objects for the guild. 
	// Requires the MANAGE_ROLES permission.
	// std::vector<Role> ModifyRolePosition(const Snowflake &role_id, int position);

	// TODO
	// Modify a guild role.
	// Requires the MANAGE_ROLES permission.
	// Role ModifyRolePosition(const Snowflake &role_id, const std::string &name, const std::string &permissions, int color, bool hoist, bool mentionable);

	// TODO
	// Delete a guild role.
	// Requires the MANAGE_ROLES permission. 
	void DeleteRole(const Snowflake &role_id);

	// TODO
	// Returns an object with one 'pruned' key indicating the number of members that would be removed in a prune operation.
	// Requires the KICK_MEMBERS permission.
	// Nu stiu ce returneaza. Trebuie sa verific.
	void GetGuildPruneRole(int days, std::vector<Snowflake> include_roles);

	// TODO
	// Begin a prune operation. 
	// Requires the KICK_MEMBERS permission.
	void BeginGuildPrune(int days, bool compute_prune_count, std::vector<Snowflake> include_roles);

	// TODO
	// Returns a list of voice region objects for the guild.
	std::vector<VoiceRegion> GetGuildVoiceRegions();

	// TODO
	// Returns a list of invite objects (with invite metadata) for the guild.
	// Requires the MANAGE_GUILD permission.
	std::vector<Invite> GetInvites();

	// TODO
	// Returns a list of integration objects for the guild.
	// Requires the MANAGE_GUILD permission.
	// std::vector<Integration> GetIntegrations();

	// TODO
	// Attach an integration object from the current user to the guild.
	// Requires the MANAGE_GUILD permission.
	void CreateIntegration(const std::string &type, const Snowflake &id);

	// TODO
	// Modify the behavior and settings of an integration object for the guild.
	// Requires the MANAGE_GUILD permission.
	void ModifyIntegration(const Snowflake &integrastion_id, int expire_behavior, int expire_grace_period, int enable_emoticons);

	// TODO
	// Delete the attached integration object for the guild. 
	// Requires the MANAGE_GUILD permission. 
	void DeleteIntegration(const Snowflake &integrastion_id);

	// TODO
	// Sync an integration. 
	// Requires the MANAGE_GUILD permission.
	void SyncIntegration(const Snowflake &integrastion_id);
};

