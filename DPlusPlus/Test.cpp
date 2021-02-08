#include <iostream>
#include <string>
#include <conio.h>

#include "Discord.h"
#include "Utilities.h"

using namespace std;

class Bot: public Discord {

public:
	void OnReady(Ready &ready) override {
		cout << "Botul este pe " << ready.unavailableGuilds.size() << " servere. \n";
		cout << "Bot: " << ready.user.username << "\n";
	}

	void OnMessageCreate(const Message &message) override {
		cout << "Mesaj trimis de: " << message.author.username << "\n";
		cout << "Content mesaj: " << message.content << "\n";
		cout << "Tip mesaj: " << message.type << "\n";
	}

	void OnChannelCreate(const Channel &channel) {
		cout << "A fost creat canalul: " << channel.name << "\n";
		cout << "Id-ul serverului: " << channel.guild_id << "\n";
	}

	void OnMessageUpdate(const Message &message) {
		cout << "Mesajul a fost updatat: " << message.id << "\n";
		cout << "Mesaj: " << message.content << "\n";
	}

};

int main() {
	Bot bot;
	bot.Start("Nzk1NzU1ODUxOTgxMzg5ODY0.X_N_Yw.wUJJdnobq246l5p60-jNQZy9ldM");

	_getch();
	return 0;
}