#include <iostream>
#include <string>
#include <conio.h>

#include "Discord.h"

#include "Message.h"

using namespace std;

class Bot: public Discord {

public:
	void OnReady(Ready &ready) {
		cout << "READY";
	}

};

int main() {
	Message m;
	m.content = "Salut";
	m.guild_id = "123";
	m.timestamp = " ieri";

	nJson j;
	m.ToJson(j);
	cout << j.dump(5);

	//Bot bot;
	//bot.Start("");
	Bot bot;
	bot.Start("");

	_getch();
}
