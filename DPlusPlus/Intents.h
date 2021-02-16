enum eIntents: int {
	GUILDS						/**/ = 1 << 0,
	GUILD_MEMBERS				/**/ = 1 << 1,
	GUILD_BANS					/**/ = 1 << 2,
	GUILD_EMOJIS				/**/ = 1 << 3,
	GUILD_INTEGRATIONS			/**/ = 1 << 4,
	GUILD_WEBHOOKS				/**/ = 1 << 5,
	GUILD_INVITES				/**/ = 1 << 6,
	GUILD_VOICE_STATES			/**/ = 1 << 7,
	GUILD_PRESENCES				/**/ = 1 << 8,
	GUILD_MESSAGES				/**/ = 1 << 9,
	GUILD_MESSAGE_REACTIONS		/**/ = 1 << 10,
	GUILD_MESSAGE_TYPING		/**/ = 1 << 11,
	DIRECT_MESSAGES				/**/ = 1 << 12,
	DIRECT_MESSAGE_REACTIONS	/**/ = 1 << 13,
	DIRECT_MESSAGE_TYPING		/**/ = 1 << 14
};

class Intents {

private:
	int value = 0;

public:
	Intents() {
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

	void AddIntents(eIntents intents) {
		value |= intents;
	}

	int GetIntents() { return value; }
};
