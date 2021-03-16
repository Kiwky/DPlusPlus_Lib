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
