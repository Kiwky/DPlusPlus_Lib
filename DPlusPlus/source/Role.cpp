#include "Role.h"

Role::Role(const nJson &data) {
	GetJson(data, "id",				/**/ id);
	GetJson(data, "name",			/**/ name);
	GetJson(data, "color",			/**/ color);
	GetJson(data, "hoist",			/**/ hoist);
	GetJson(data, "position",		/**/ position);
	GetJson(data, "permissions",	/**/ permissions);
	GetJson(data, "managed",		/**/ managed);
	GetJson(data, "mentionable",	/**/ mentionable);
}
