#include <iostream>
#include <string>
#include <conio.h>
#include "Discord.h"

using namespace std;

class Bot: public Discord {

public:
	// Functii

};

int main() {
	Bot bot;
	bot.Start("BOT TOKEN :)");

	_getch();
}