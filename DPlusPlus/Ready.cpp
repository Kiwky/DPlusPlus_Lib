#include "Ready.h"
#include "Utilities.h"

Ready::Ready(const nJson &data) {
	this->gVersion		/**/ = data["v"];
	this->session_id	/**/ = data["session_id"];
	this->user			/**/ = User(data["user"]);

	DPlusPlus::Template::GetJsonVector(data, "guilds",			 /**/ this->unavailableGuilds);
	DPlusPlus::Template::GetJsonVector(data, "private_channels", /**/ this->privateChannels);
}