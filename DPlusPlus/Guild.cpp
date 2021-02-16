#include "Guild.h"
#include "Utilities.h"

Unavailable_Guild::Unavailable_Guild(const nJson &data) {
	DPlusPlus::Template::GetJson(data, "id",			/**/ this->id);
	DPlusPlus::Template::GetJson(data, "unavailable",	/**/ this->unavailable);
}