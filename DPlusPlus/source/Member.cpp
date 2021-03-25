#include "Member.h"
#include "User.h"

Member::Member(const nJson &data) {
	if(data.contains("user"))
		user = new User(data["user"]);

	GetJson(data, "nick",			/**/ nick);
	GetJson(data, "joined_at",		/**/ joined_at);
	GetJson(data, "premium_since",	/**/ premium_since);
	GetJson(data, "deaf",			/**/ deaf);
	GetJson(data, "mute",			/**/ mute);
	GetJson(data, "pending",		/**/ pending);
	GetJson(data, "permissions",	/**/ permissions);

	//GetJsonVector(data, "roles",	/**/ roles);
}
