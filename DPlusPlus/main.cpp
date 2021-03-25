#include <iostream>
#include <string>
#include <conio.h>
#include <nlohmann/json.hpp>

#include "Discord.h"
#include "Invite.h"
#include "Guild.h"
#include "windows.h"

using namespace std;
using nJson = nlohmann::json;

class Bot: public Discord {

public:
	void OnReady(const Ready &ready) {}

	void OnMessageCreated(const Message &message) {
		printf("Message created: [%s] %s \n", message.channel_id.c_str(), message.content.c_str());

		cout << message.channel->name << "\n";

		if(message.content == "ping") {
			message.channel->SendMessage("pong");
		}
	}

	void OnMessageUpdated(const Message &message) {
		printf("Message updated: [%s - %s] %s \n",
			   message.guild_id.c_str(),
			   message.channel_id.c_str(),
			   message.id.c_str()
		);
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
};

int main() {
	Bot bot;
	bot.Start("");

	_getch();
}
