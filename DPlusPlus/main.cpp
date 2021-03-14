#include <iostream>
#include <string>
#include <conio.h>

#include "Discord.h"

using namespace std;

class Bot: public Discord {
};

int main() {
	Bot bot;
	bot.Start("Nzk1NzU1ODUxOTgxMzg5ODY0.X_N_Yw.pdGlOP4Xvq9eHrIig6hjU50ufgQ");

	_getch();
}