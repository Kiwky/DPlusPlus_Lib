#pragma once

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

#include "Utilities.h"
#include "Guild.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

enum User_Flags {
	NONE				/**/ = 0,
	DISCORD_EMPLOYEE	/**/ = 1 << 0,
	PARTNERED			/**/ = 1 << 1,
	HYPE_SQUAD			/**/ = 1 << 2,
	BUG_HUNTER_1		/**/ = 1 << 3,
	HOUSE_BRAVERY		/**/ = 1 << 6,
	HOUSE_BRILLIANCE	/**/ = 1 << 7,
	HOUSE_BALANCE		/**/ = 1 << 8,
	EARLY_SUPPORT		/**/ = 1 << 9,
	TEAM_USER			/**/ = 1 << 10,
	SYSTEM				/**/ = 1 << 12,
	BUG_HUNTER_2		/**/ = 1 << 14,
	VERIFIED_BOT		/**/ = 1 << 16,
	EARLY_BOT_DEV		/**/ = 1 << 17
};

class User {

public:
	Snowflake id;
	int premium_type;
	int public_flags;
	bool bot;
	bool system;
	bool mfa_enabled;
	bool verified;
	User_Flags flags;
	std::string username;
	std::string discriminator;
	std::string avatar;
	std::string locale;
	std::string email;

public:
	User() {}
	User(const Snowflake &user_id);
	User(const nJson &data);

public:
	void ToJson(nJson &j);

	// TODO
	// Modify the requester's user account settings.
	User ModifyBot(const std::string username, /*Image image*/);

	// TODO
	// Returns a list of partial guild objects the current user is a member of. 
	// Requires the guilds OAuth2 scope.
	Guild GetUserGuilds();

	// TODO
	// Leave a guild.
	void LeaveGuild();
};

