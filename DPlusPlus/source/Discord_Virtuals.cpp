#include "Discord.h"
#include "Log.h"

void Discord::OnReady(Ready &ready) {
	Log::Print(Info, "Client is ready.");
}