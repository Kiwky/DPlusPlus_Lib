#include "Discord.h"
#include "Log.h"

void Discord::OnReady(const Ready &ready) {
	Log::Print(Info, "Client is ready.");
}

void Discord::OnChannelCreated(const Channel &channel) {
	Log::Print(Info, "Channel created.");
}

void Discord::OnChannelDeleted(const Channel &channel) {
	Log::Print(Info, "Channel deleted.");
}

void Discord::OnMessageCreated(const Message &message) {
	Log::Print(Info, "Message created.");
}

void Discord::OnMessageUpdated(const Message &message) {
	Log::Print(Info, "Message updated.");
}

void Discord::OnMessageDeleted(const MessageDelete &message) {
	Log::Print(Info, "Message deleted.");
}

void Discord::OnMessageDeletedBulk(const MessageDeleteBulk &message) {
	Log::Print(Info, "Message deleted bulk.");
}

void Discord::OnMessageReactionAdd(const Member &member, const Snowflake &guild_id, const Snowflake &channel_id, const Snowflake &message_id) {
	Log::Print(Info, "Message reaction added.");
}

void Discord::OnMessageReactionDeleted(const User &user, const Snowflake &guild_id, const Snowflake &channel_id, const Snowflake &message_id) {
	Log::Print(Info, "Message reaction deleted.");
}

void Discord::OnMessageReactionDeletedAll(const Snowflake &guild_id, const Snowflake &channel_id, const Snowflake &message_id) {
	Log::Print(Info, "Message reaction deleted all.");
}

void Discord::OnMessageReactionRemoveEmoji(const Emoji &emoji, const Snowflake &guild_id, const Snowflake &channel_id, const Snowflake &message_id) {
	Log::Print(Info, "Message reaction removed by bot.");
}

void Discord::OnVoiceStateUpdate(const Voice &voice) {
	Log::Print(Info, "Voice state updated.");
}

void Discord::OnInviteCreated(const Invite &invite) {
	Log::Print(Info, "New invite was created.");
}

void Discord::OnInviteDeleted(const Snowflake &guiild_id, const Snowflake &channel_id, const std::string &code) {
	Log::Print(Info, "Invite deleted.");
}
