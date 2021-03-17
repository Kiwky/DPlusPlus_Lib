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

			Message m;
			Embed e;
			e.AddField("Fiel 1", "Value 1", true);
			e.AddField("Fiel 2", "Value 2", true);
			e.AddField("Fiel 3", "Value 3", true);
			e.AddField("Fiel 4", "Value 4", true);
			e.AddField("Fiel 5", "Value 5", true);
			e.AddField("Fiel 6", "Value 6", true);
			m.content = "EMBED";

			m.embeds = e;

			nJson j;
			m.ToJson(j);

			t.SendMessage("CONTENT :)", &e);
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
