#include "Invite.h"
#include "Channel.h"
#include "Guild.h"

Invite::Invite(const Snowflake &invite_id) {
	*this = Invite(API_Call("/invites/" + invite_id, methods::GET));
}

Invite::Invite(const nJson &data) {
	if(data.contains("inviter"))
		inviter = User(data["inviter"]);

	if(data.contains("channel_id"))
		channel = new Channel(data["channel_id"].get<std::string>());

	if(data.contains("guild_id"))
		guild = new Guild(data["guild_id"].get<std::string>());

	GetJson(data, "code", code);
}

void Invite::Delete() {

}

