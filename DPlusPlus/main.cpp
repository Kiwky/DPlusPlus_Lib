#include <iostream>
#include <string>
#include <conio.h>
#include <nlohmann/json.hpp>

#include "Discord.h"
#include "Invite.h"
#include "Channel.h"
#include "Guild.h"
#include "windows.h"

using namespace std;
using nJson = nlohmann::json;

class Bot: public Discord {

public:
	void OnReady(const Ready &ready) {
		ModifyPresence("Status :) 2");
	}

	void OnMessageCreated(const Message &message) {
		printf("Message created: [%s] %s \n", message.channel_id.c_str(), message.content.c_str());

		//cout << message.channel->name << "\n";
		/*if(message.content == "ping") {
			message.channel->SendMessage("pong");
		}*/
	}

	void OnMessageUpdated(const Message &message) {
		printf("Message updated: [%s - %s] %s \n",
			   message.guild_id.c_str(),
			   message.channel_id.c_str(),
			   message.id.c_str()
		);
	}

	void OnMessageReactionDeletedAll(const Snowflake &guild_id, const Snowflake &channel_id, const Snowflake &message_id) {
		//cout << "Deleted all reactions \n";
	}

	void OnMessageDeleted(const MessageDelete &message) {
		printf("Message deleted: [%s - %s] %s \n",
			   message.guild_id.c_str(),
			   message.channel_id.c_str(),
			   message.id.c_str()
		);
	}

	void OnMessageDeletedBulk(const MessageDeleteBulk &message) {
		for(int i = 0; i < (int)message.id.size(); i++) {
			cout << message.id[i] << "\n";
		}
	}

	void OnMessageReactionAdd(const Member &member, const Snowflake &guild_id, const Snowflake &channel_id, const Snowflake &message_id) {
		cout << member.user->username << " added reaction. \n";
		cout << "1: " << member.user->id << "\n";
	}

	void OnMessageReactionDeleted(const User &user, const Snowflake &guild_id, const Snowflake &channel_id, const Snowflake &message_id) {
		/*cout << user.username << " deleted reaction. \n";
		cout << "1: " << user.id << "\n";*/
	}

	void OnVoiceStateUpdate(const Voice &voice) {
		Channel c((Snowflake)"772188152869814322");

		Embed e;
		if(voice.channel_id.empty()) {
			e.color = 15158332;
			e.description = voice.member->user->username + " s-a deconectat";
		}
		else {
			e.color = 3066993;
			e.description = voice.member->user->username + " s-a conectat";
		}

		c.SendMessage("", &e);
	}
};

int main() {
	Bot bot;
	bot.Start("");

	_getch();
}
