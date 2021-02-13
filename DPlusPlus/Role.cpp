#include "Role.h"
#include "Utilities.h"

Role::Role(const nJson &data) {
	DPlusPlus::Template::GetJson(data, "color",			/**/ this->color);
	DPlusPlus::Template::GetJson(data, "position",		/**/ this->position);
	DPlusPlus::Template::GetJson(data, "id",			/**/ this->id);
	DPlusPlus::Template::GetJson(data, "name",			/**/ this->name);
	DPlusPlus::Template::GetJson(data, "permissions",	/**/ this->permissions);
	DPlusPlus::Template::GetJson(data, "hoist",			/**/ this->hoist);
	DPlusPlus::Template::GetJson(data, "managed",		/**/ this->managed);
	DPlusPlus::Template::GetJson(data, "mentionable",	/**/ this->mentionable);
}