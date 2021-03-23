#include "User.h"

User::User(const Snowflake &user_id) {
	*this = API_Call("/users/" + user_id, methods::GET);
}

User::User(const nJson &data) {
	GetJson(data, "flags",			/**/ flags);
	GetJson(data, "premium_type",	/**/ premium_type);
	GetJson(data, "bot",			/**/ bot);
	GetJson(data, "system",			/**/ system);
	GetJson(data, "mfa_enabled",	/**/ mfa_enabled);
	GetJson(data, "verified",		/**/ verified);
	GetJson(data, "flags",			/**/ flags);
	GetJson(data, "email",			/**/ email);
	GetJson(data, "locale",			/**/ locale);
	GetJson(data, "username",		/**/ username);
	GetJson(data, "discriminator",	/**/ discriminator);
	GetJson(data, "avatar",			/**/ avatar);
}

void User::ToJson(nJson &j) {
	j = nJson{
		{ "flags",			flags			},
		{ "premium_type",	premium_type	},
		{ "bot",			bot				},
		{ "system",			system			},
		{ "mfa_enabled",	mfa_enabled		},
		{ "verified",		verified		},
		{ "flags",			flags			},
		{ "email",			email			},
		{ "locale",			locale			},
		{ "username",		username		},
		{ "discriminator",	discriminator	},
		{ "avatar",			avatar			},
	};
}

//User User::ModifyBot(const std::string username /*,Image image*/) {
//
//}
//
//Guild User::GetUserGuilds() {
//	return Guild();
//}

void User::LeaveGuild() {

}
