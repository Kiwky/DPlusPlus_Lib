#include "Ready.h"

Ready::Ready(const nJson &data) {
	this->gateway_version	/**/ = data["v"];
	this->session_id		/**/ = data["session_id"];
}