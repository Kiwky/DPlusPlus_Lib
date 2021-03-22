#include "Guild.h"

Guild::Guild(const Snowflake &guild_id) {
	*this = Guild(API_Call("/guilds/" + guild_id, methods::GET));
}

Guild::Guild(const nJson &data) {
	GetJson(data, "id",								/**/ id);
	GetJson(data, "owner_id",						/**/ owner_id);
	GetJson(data, "afk_channel_id",					/**/ afk_channel_id);
	GetJson(data, "widget_channel_id",				/**/ widget_channel_id);
	GetJson(data, "application_id",					/**/ application_id);
	GetJson(data, "system_channel_id",				/**/ system_channel_id);
	GetJson(data, "rules_channel_id",				/**/ rules_channel_id);
	GetJson(data, "public_updates_channel_id",		/**/ public_updates_channel_id);
	GetJson(data, "afk_timeout",					/**/ afk_timeout);
	GetJson(data, "verification_level",				/**/ verification_level);
	GetJson(data, "default_message_notifications",	/**/ default_message_notifications);
	GetJson(data, "expliciti_content_filter",		/**/ expliciti_content_filter);
	GetJson(data, "mfa_level",						/**/ mfa_level);
	GetJson(data, "system_channel_flags",			/**/ system_channel_flags);
	GetJson(data, "member_count",					/**/ member_count);
	GetJson(data, "max_presences",					/**/ max_presences);
	GetJson(data, "max_members",					/**/ max_members);
	GetJson(data, "premium_tier",					/**/ premium_tier);
	GetJson(data, "premium_subscription_count",		/**/ premium_subscription_count);
	GetJson(data, "max_video_channel_users",		/**/ max_video_channel_users);
	GetJson(data, "afk_timeout",					/**/ afk_timeout);
	GetJson(data, "approximate_member_count",		/**/ approximate_member_count);
	GetJson(data, "approximate_presence_count",		/**/ approximate_presence_count);
	GetJson(data, "owner",							/**/ owner);
	GetJson(data, "widget_enabled",					/**/ widget_enabled);
	GetJson(data, "large",							/**/ large);
	GetJson(data, "unavailable",					/**/ unavailable);
	GetJson(data, "name",							/**/ name);
	GetJson(data, "icon",							/**/ icon);
	GetJson(data, "icon_hash",						/**/ icon_hash);
	GetJson(data, "splash",							/**/ splash);
	GetJson(data, "discovery_splash",				/**/ discovery_splash);
	GetJson(data, "permissions",					/**/ permissions);
	GetJson(data, "regions",						/**/ regions);
	GetJson(data, "joined_at",						/**/ joined_at);
	GetJson(data, "vanity_url_code",				/**/ vanity_url_code);
	GetJson(data, "description",					/**/ description);
	GetJson(data, "banner",							/**/ banner);
	GetJson(data, "preferred_locale",				/**/ preferred_locale);

	GetJsonVector(data, "channels",					/**/ channels);
	GetJsonVector(data, "members",					/**/ members);
	GetJsonVector(data, "emojis",					/**/ emojis);

}

std::vector<Emoji> Guild::ListEmoji() {
	return std::vector<Emoji>();
}

Emoji Guild::GetEmoji(const Snowflake &emoji_id) {
	return Emoji();
}

Emoji Guild::CreateEmoji(const std::string &name, /*Image image*/ std::vector<Snowflake> *roles /*= nullptr*/) {
	return Emoji();
}

Emoji Guild::ModifyEmoji(const std::string &name, std::vector<Snowflake> *roles /*= nullptr*/) {
	return Emoji();
}

void Guild::DeleteEmoji(const Snowflake &emoji_id) {

}

GuildPreview Guild::GetGuildPreview() {
	return GuildPreview();
}

Guild Guild::ModifyGuild(const std::string &name, const std::string &region, int verification_level, int default_message_notifications, int explicit_content_filter, int afk_timeout, const Snowflake &afk_channel_id /*,Image splash, Image banner*/) {
	return Guild();
}

void Guild::DeleteGuild() {

}

std::vector<Channel> Guild::GetChannels() {
	return std::vector<Channel>();
}

Channel Guild::CreateChannel(/*Lista parametrii*/) {
	return Channel();
}

void Guild::ModifyChannel(const Snowflake &channel_id, int new_position) {

}

Member Guild::GetMember(const Snowflake &user_id) {
	return Member();
}

std::vector<Member> Guild::GetMembers() {
	return std::vector<Member>();
}

Member Guild::ModifyMember(const Snowflake &user_id, const std::string &new_nick, std::vector<Snowflake> roles, bool mute, bool deaf, const Snowflake &channel_id) {
	return Member();
}

void Guild::ModifyMemberNickname(const Snowflake &user_id, const std::string &new_nick) {

}

void Guild::AddMemberRole(const Snowflake &user_id, const Snowflake &role_id) {

}

void Guild::RemoveMemberRole(const Snowflake &user_id, const Snowflake &role_id) {

}

void Guild::RemoveMemberRole(const Snowflake &user_id) {

}

/*
Ban Guild::GetGuildBan(const Snowflake &user_id) {

}

std::vector<Ban> Guild::GetGuildBans() {

}
*/

void Guild::Ban(const Snowflake &user_id, const std::string reason /*= ""*/, int delete_message_days /*= 0*/) {

}

void Guild::RemoveBan(const Snowflake &user_id) {

}

/*
std::vector<Role> Guild::GetRoles() {

}

Role Guild::CreateRole(const std::string &name, const std::string permissions, int color, bool hoist, bool mentionable) {

}

std::vector<Role> Guild::ModifyRolePosition(const Snowflake &role_id, int position) {

}

Role Guild::ModifyRolePosition(const Snowflake &role_id, const std::string &name, const std::string &permissions, int color, bool hoist, bool mentionable) {

}
*/

void Guild::DeleteRole(const Snowflake &role_id) {

}

