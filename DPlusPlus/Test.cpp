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

	void OnMessageDelete(const MessageDeleteArg &message) {
		cout << "Mesajul a fost sters: " << message.id << "\n";
		cout << "Mesaj: " << message.channe_id << "\n";
	}

	void OnVoiceState(const Voice &voice) {
		if(voice.channel_id == "") {
			cout << "Disconnect\n";
		}
		else cout << "Connected\n";
	}

	void OnRoleCreate(std::string &guild_id, const Role &role) {
		cout << "Role: " << role.name << "\n";
		cout << "Role id: " << role.id << "\n";
		cout << "Guild id: " << guild_id << "\n";
	}

	void OnChannelPinsUpdate(std::string &guild_id, std::string &channel_id, std::string &last_pin_time) {
		cout << "GID: " << guild_id << "\n";
		cout << "CID: " << channel_id << "\n";
		cout << "LT: " << last_pin_time << "\n";
	}

	void OnReactionAdd(const Member &member, const std::string &user_id, const std::string &guild_id, const std::string &channel_id, const std::string &message_id) {
		cout << "Member name: " << member.user.username << "\n";
		cout << "User id: " << user_id << "\n";
		cout << "Channel id: " << channel_id << "\n";
	}

	void OnReactionRemove(const std::string &user_id, const std::string &guild_id, const std::string &channel_id, const std::string &message_id) {
		cout << "User id: " << user_id << "\n";
		cout << "Guild id: " << guild_id << "\n";
		cout << "Channel id: " << channel_id << "\n";
	}

	void OnMemberAdd(const std::string guild_id, const Member &member) {
		cout << "New member: " << member.user.username << "\n";
		cout << "Guild id: " << guild_id << "\n";
	}

	void OnGuildDelete(const Unavailable_Guild &guild) {
		cout << "GID: " << guild.id << "\n";
		cout << "GUN: " << guild.unavailable << "\n";
	}

	void OnGuildCreate(const Guild &guild) {
		cout << "New guild: " << guild.id << "\n";
	}

	void OnMemberBan(const std::string guild_id, const User &user) {
		cout << "Member banned: " << user.username << "\n";
		cout << "GID: " << guild_id << "\n";
	}
};

int main() {
	Bot bot;
	bot.Start("");

	_getch();
	return 0;
}


