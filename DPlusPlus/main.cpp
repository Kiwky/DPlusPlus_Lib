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

		Guild g;
		g.description = "SALUT";

		nJson j;

		j["guild"]["description"] = g.description;
		j["channel"]["id"] = "12";

		cout << j.dump(4);

		while(true) {
			Invite i(j);
			cout << i.guild->description;

		}

		/*Channel c(message.channel_id);
		vector<Invite> list = c.GetInvites();
		for(int i = 0; i < (int)list.size(); i++) {

			cout << list[i].code << "\n";
		}*/
		//Guild g(message.guild_id);

		//g.ModifyMember();

		//cout << g.name;
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
};

int main() {
	Bot bot;
	bot.Start("Nzk1NzU1ODUxOTgxMzg5ODY0.X_N_Yw.6TCEPvojYPxrKyfYw8w66JSz0fA");

	_getch();
}
