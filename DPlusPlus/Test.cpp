#include <iostream>
#include <string>
#include <conio.h>
#include "Discord.h"
#include "Utilities.h"

using namespace std;

class Bot: public Discord {

public:
	void OnReady() override {}

};

int main() {
	Bot bot;
	bot.Start("");

	_getch();
}