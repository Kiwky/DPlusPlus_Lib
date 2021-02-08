#include "Discord.h"

void Discord::OnReady(Ready &ready) {
	Log::Print(Info, "Client is ready.");
}

void Discord::OnHeartBeat() {
	Log::Print(Info, "Client heartbeat.");
}

void Discord::OnMessageCreate(const Message &message) {
	Log::Print(Info, "Message created.");
}

void Discord::OnMessageUpdate(const Message &message) {
	Log::Print(Info, "Message update.");
}

void Discord::OnChannelCreate(const Channel &channel) {
	Log::Print(Info, "Channel created.");
}