#include "Emoji.h"
#include "User.h"

Emoji::Emoji(const nJson &data) {
	if(data.contains("user"))
		this->user = new User(data["user"]);

	GetJson(data, "id",					/**/ id);
	GetJson(data, "require_colons",		/**/ require_colons);
	GetJson(data, "managed",			/**/ managed);
	GetJson(data, "animated",			/**/ animated);
	GetJson(data, "available",			/**/ available);

	GetJsonVector(data, "roles", roles);
}
