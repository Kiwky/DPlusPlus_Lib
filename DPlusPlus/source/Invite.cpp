#include "Invite.h"
#include "Channel.h"

Invite::Invite(const nJson &data): channel(new Channel(data["channel"])) {
	//if(data.contains("guild"))
		//this->guild = User(data["guild"]);

	if(data.contains("inviter"))
		this->inviter = User(data["inviter"]);

	GetJson(data, "code", code);
}