#include "Discord.h"
#include "Log.h"

void Discord::OnReady(const Ready &ready) {
	Log::Print(Info, "Client is ready.");
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
