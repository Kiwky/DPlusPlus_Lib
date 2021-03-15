#include <iostream>
#include <string>
#include <conio.h>

#include "Discord.h"

#include "Message.h"

using namespace std;

class Bot: public Discord {

public:
	void OnMessageCreated(const Message &message) {
		printf("Message created: [%s] %s", message.channel_id.c_str(), message.content.c_str());
	}
};

int main() {
	Bot bot;
	bot.Start("");

	_getch();
}
