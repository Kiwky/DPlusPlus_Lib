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

void Discord::OnMessageDelete(const MessageDeleteArg &message) {
	Log::Print(Info, "Message delete.");
}

void Discord::OnChannelCreate(const Channel &channel) {
	Log::Print(Info, "Channel created.");
}

void Discord::OnChannelUpdate(const Channel &channel) {
}

void Discord::OnChannelDelete(const Channel &channel) {
}

void Discord::OnVoiceState(const Voice &voice) {
	Log::Print(Info, "Voice state.");
}

void Discord::OnRoleCreate(std::string &guild_id, const Role &role) {
	Log::Print(Info, "Role create.");
}

void Discord::OnRoleUpdate(std::string &guild_id, const Role &role) {
	Log::Print(Info, "Role update.");
}

void Discord::OnRoleDelete(std::string &guild_id, const Role &role) {
	Log::Print(Info, "Role delete.");
}

void Discord::OnChannelPinsUpdate(std::string &guild_id, std::string &channel_id, std::string &last_pin_time) {
	Log::Print(Info, "Pins channel update.");
}