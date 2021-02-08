#include "User.h"
#include "Utilities.h"

User::User(const nJson &data) {
	DPlusPlus::Template::GetJson(data, "flags",			/**/ this->flags);
	DPlusPlus::Template::GetJson(data, "premium_type",	/**/ this->premium_type);
	DPlusPlus::Template::GetJson(data, "bot",			/**/ this->bot);
	DPlusPlus::Template::GetJson(data, "system",		/**/ this->system);
	DPlusPlus::Template::GetJson(data, "mfa_enabled",	/**/ this->mfa_enabled);
	DPlusPlus::Template::GetJson(data, "verified",		/**/ this->verified);
	DPlusPlus::Template::GetJson(data, "flags",			/**/ this->flags);
	DPlusPlus::Template::GetJson(data, "email",			/**/ this->email);
	DPlusPlus::Template::GetJson(data, "locale",		/**/ this->locale);
	DPlusPlus::Template::GetJson(data, "username",		/**/ this->username);
	DPlusPlus::Template::GetJson(data, "discriminator",	/**/ this->discriminator);
	DPlusPlus::Template::GetJson(data, "avatar",		/**/ this->avatar);
}