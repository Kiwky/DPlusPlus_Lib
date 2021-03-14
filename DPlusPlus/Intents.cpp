#include "Intents.h"

Intents::Intents() {
	AddIntents(GUILDS);
	AddIntents(GUILD_MEMBERS);
	AddIntents(GUILD_BANS);
	AddIntents(GUILD_EMOJIS);
	AddIntents(GUILD_INTEGRATIONS);
	AddIntents(GUILD_WEBHOOKS);
	AddIntents(GUILD_INVITES);
	AddIntents(GUILD_VOICE_STATES);
	AddIntents(GUILD_PRESENCES);
	AddIntents(GUILD_MESSAGES);
	AddIntents(GUILD_MESSAGE_REACTIONS);
	AddIntents(GUILD_MESSAGE_TYPING);
	AddIntents(DIRECT_MESSAGES);
	AddIntents(DIRECT_MESSAGE_REACTIONS);
	AddIntents(DIRECT_MESSAGE_TYPING);
}

void Intents::AddIntents(eIntents intents) {
	value |= intents;
}

int Intents::GetIntents() { return value; }
