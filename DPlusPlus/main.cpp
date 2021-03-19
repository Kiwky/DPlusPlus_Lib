#include <iostream>
#include <string>
#include <conio.h>
#include <nlohmann/json.hpp>

#include "Discord.h"

using namespace std;
using nJson = nlohmann::json;

class Bot: public Discord {

public:
	void OnReady(const Ready &ready) {}

	void OnMessageCreated(const Message &message) {
		printf("Message created: [%s] %s \n", message.channel_id.c_str(), message.content.c_str());

		if(!message.author.bot) {
			Channel t(message.channel_id);

			/*Embed e;

			e.title = "Titlu";

			e.AddField("Field 1", "Value 1", true);
			e.AddField("Field 2", "Value 2", true);
			e.AddField("Field 3", "Value 3", true);
			e.AddField("Field 4", "Value 4", true);
			e.AddField("Field 5", "Value 5", true);
			e.AddField("Field 6", "Value 6", true);

			e.footer = Embed_Footer{"Titlu footer"};*/


			t.SendMessage("CONTENT :)");
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
};

int main() {
	Bot bot;
	bot.Start("");

	_getch();
}
