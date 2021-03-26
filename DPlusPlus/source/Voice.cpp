#include "Voice.h"
#include "Member.h"

Voice::Voice(const nJson &data) {
	if(data.contains("member")) {
		this->member = new Member(data["member"]);
	}

	GetJson(data, "guild_id",		/**/ guild_id);
	GetJson(data, "channel_id",		/**/ channel_id);
	GetJson(data, "user_id",		/**/ user_id);
	GetJson(data, "deaf",			/**/ deaf);
	GetJson(data, "mute",			/**/ mute);
	GetJson(data, "self_deaf",		/**/ self_deaf);
	GetJson(data, "self_mute",		/**/ self_mute);
	GetJson(data, "self_stream",	/**/ self_stream);
	GetJson(data, "self_video",		/**/ self_video);
	GetJson(data, "supress",		/**/ supress);
	GetJson(data, "session_id",		/**/ session_id);
}
