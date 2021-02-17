#include "Discord.h"

void Discord::OnReady(Ready &ready) {
	Log::Print(Info, "Client is ready.");
}

void Discord::OnHeartBeat() {
	Log::Print(Info, "Client heartbeat.");
}

void Discord::OnMemberAdd(const std::string guild_id, const Member &member) {
	Log::Print(Info, "Member add.");
}

void Discord::OnMemberRemove(const std::string guild_id, const User &user) {
	Log::Print(Info, "Member remove.");
}

void Discord::OnMemberUpdate(const std::string guild_id, const User &user, const std::string &nick, const std::string &joined_at) {
	Log::Print(Info, "Member update.");
}

void Discord::OnMemberBan(const std::string guild_id, const User &user) {
	Log::Print(Info, "Member ban.");
}

void Discord::OnMemberUnBan(const std::string guild_id, const User &user) {
	Log::Print(Info, "Member unban.");
}

void Discord::OnMemberPresenceUpdate(const User &user, const std::string &guild_id, const std::string &status) {
	Log::Print(Info, "Presence update.");
}

void Discord::OnMessageCreate(const Message &message) {
	Log::Print(Info, "Message created.");
}

void Discord::OnMessageUpdate(const Message &message) {
	Log::Print(Info, "Message update.");
}

void Discord::OnMessageDelete(const MessageDeleteArg &message) {
	Log::Print(Info, "Message delete.");
}

void Discord::OnChannelCreate(const Channel &channel) {
	Log::Print(Info, "Channel created.");
}

void Discord::OnChannelUpdate(const Channel &channel) {
	Log::Print(Info, "Channel update.");
}

void Discord::OnChannelDelete(const Channel &channel) {
	Log::Print(Info, "Channel delete.");
}

void Discord::OnGuildCreate(const Guild &guild) {
	Log::Print(Info, "Guild create.");
}

void Discord::OnGuildUpdate(const Guild &guild) {
	Log::Print(Info, "Guild update.");
}

void Discord::OnGuildDelete(const Unavailable_Guild &guild) {
	Log::Print(Info, "Guild delete.");
}

void Discord::OnVoiceState(const Voice &voice) {
	Log::Print(Info, "Voice state.");
}

void Discord::OnRoleCreate(const std::string &guild_id, const Role &role) {
	Log::Print(Info, "Role create.");
}

void Discord::OnRoleUpdate(const std::string &guild_id, const Role &role) {
	Log::Print(Info, "Role update.");
}

void Discord::OnRoleDelete(const std::string &guild_id, const std::string &role_id) {
	Log::Print(Info, "Role delete.");
}

void Discord::OnChannelPinsUpdate(const std::string &guild_id, const std::string &channel_id, const std::string &last_pin_time) {
	Log::Print(Info, "Pins channel update.");
}

void Discord::OnReactionAdd(const Member &member, const std::string &user_id, const std::string &guild_id, const std::string &channel_id, const std::string &message_id) {
	Log::Print(Info, "Reaction add.");
}

void Discord::OnReactionRemove(const std::string &user_id, const std::string &guild_id, const std::string &channel_id, const std::string &message_id) {
	Log::Print(Info, "Reaction remove.");
}

void Discord::OnWebHooksUpdate(const std::string &guild_id, const std::string &channel_id) {
	Log::Print(Info, "Webhook update.");
}

void Discord::OnInviteCreate(const User &user, const std::string &guild_id, const std::string &channel_id, const std::string &code, int max_use, bool temporary) {
	Log::Print(Info, "Invite create.");
}

void Discord::OnInviteDelete(const std::string &guild_id, const std::string &channel_id, const std::string &code) {
	Log::Print(Info, "Invite delete.");
}
