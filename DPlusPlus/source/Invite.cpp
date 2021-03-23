#include "Invite.h"
#include "Channel.h"
#include "Guild.h"

Invite::Invite(const Snowflake &invite_id) {
	*this = Invite(API_Call("/invites/" + invite_id, methods::GET));
}

Invite::Invite(const nJson &data):
	channel(new Channel(data["channel"])), guild(new Guild(data["guild"])) {

	if(data.contains("inviter"))
		this->inviter = User(data["inviter"]);

	GetJson(data, "code", code);
}

void Invite::Delete() {

}

