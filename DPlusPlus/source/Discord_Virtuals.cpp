#include "Discord.h"
#include "Log.h"

void Discord::OnReady(const Ready &ready) {
	Log::Print(Info, "Client is ready.");
}

void Discord::OnMessageCreated(const Message &message) {
	Log::Print(Info, "Message created.");
}