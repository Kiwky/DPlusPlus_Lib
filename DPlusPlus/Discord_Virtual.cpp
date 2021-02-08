#include "Discord.h"

void Discord::OnReady(Ready &ready) {
	Log::Print(Info, "Client is ready.");
}

void Discord::OnHeartBeat() {

}