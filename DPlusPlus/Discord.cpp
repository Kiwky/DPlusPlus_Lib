#include "Discord.h"

void Discord::Start(const std::string &token) {
	if(token.length() == 0) {
		Log::Print(Error, "No token has been set.");
		return;
	}

	this->token = token;
	this->isReady = false;
	this->lastSRec = 0;

	client.set_message_handler([&](websocket_incoming_message msg) {
		try {
			ProcessBotJson(msg);
		} catch(const std::exception &e) {
			Log::Print(Error, "Message handler error [CATCH]:" + (std::string)e.what());
		}
	});

	client.connect(U("wss://gateway.discord.gg")).then([&]() {
		Log::Print(Info, "Gateway connection successful.");
		ProcessBotIdentity();
	});
}

void Discord::ProcessBotIdentity() {
	websocket_outgoing_message msg;
	nJson identity;

	identity["op"] = OP_Type::IDENTIFY;
	identity["d"] = {
		{"token", token},
		{"properties",{
			{"$os", "Windows"},
		{"$browser", "DPlusPlus"},
		{"$device", "DPlusPlus"},
		{"$referrer", ""},
		{"$referring_domain", ""}
	}},
		{"compress", false},
		{"large_threshold", 250}
	};

	// Convert 'identity' object (json object) to string and send it to server.
	msg.set_utf8_message(to_string(identity));
	client.send(msg);
}
