#include <iostream>
#include <string>
#include <conio.h>

#include "Discord.h"

#include "Message.h"

using namespace std;

class Bot: public Discord {

public:

};

int main() {
	Bot bot;
	bot.Start("Nzk1NzU1ODUxOTgxMzg5ODY0.X_N_Yw.fGg0yZb2g_JR7p162Ko22x8YFYI");

	_getch();
}
