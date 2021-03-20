#include <iostream>
#include <string>
#include <conio.h>
#include <nlohmann/json.hpp>

#include "Discord.h"
#include "Invite.h"
#include "windows.h"

using namespace std;
using nJson = nlohmann::json;

class Bot: public Discord {

public:
	void OnReady(const Ready &ready) {}

	void OnMessageCreated(const Message &message) {
		printf("Message created: [%s] %s \n", message.channel_id.c_str(), message.content.c_str());

		Channel c(message.channel_id);
		vector<Invite> list = c.GetInvites();
		for(int i = 0; i < list.size(); i++) {

			cout << list[i].code << "\n";
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
		for(int i = 0; i < message.id.size(); i++) {
			cout << message.id[i] << "\n";
		}
	}
};

int main() {
	Bot bot;
	bot.Start("");

	_getch();
}
