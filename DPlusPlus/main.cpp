#include <iostream>
#include <string>
#include <conio.h>

#include "Discord.h"

using namespace std;

class Bot: public Discord {
};

int main() {
	Bot bot;
	bot.Start("");

	_getch();
}
