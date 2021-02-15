#include "Member.h"
#include "Utilities.h"

Member::Member(const nJson &data) {
	if(data.contains("user"))
		this->user = User(data["user"]);

	DPlusPlus::Template::GetJson(data, "nick",			/**/ this->nick);
	DPlusPlus::Template::GetJson(data, "roles",			/**/ this->roles);
	DPlusPlus::Template::GetJson(data, "joined_at",		/**/ this->joined_at);
	DPlusPlus::Template::GetJson(data, "premium_since",	/**/ this->premium_since);
	DPlusPlus::Template::GetJson(data, "deaf",			/**/ this->deaf);
	DPlusPlus::Template::GetJson(data, "mute",			/**/ this->mute);
	DPlusPlus::Template::GetJson(data, "pending",		/**/ this->pending);
	DPlusPlus::Template::GetJson(data, "permissions",	/**/ this->permissions);
}