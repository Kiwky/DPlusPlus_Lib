#include "Discord.h"
#include "Intents.h"

void Discord::Start(const std::string &token) {
	if(token.length() == 0) {
		//Log::Print(Error, "No token has been set.");
		return;
	}

	this->token = token;
	this->is_ready = false;
	this->last_signal_id = 0;

	client.set_message_handler([&](websocket_incoming_message msg) {
		try {
			ProcessBotJson(msg);
		}
		catch(const std::exception &e) {
			//Log::Print(Error, "Message handler error [CATCH]: " + (std::string)e.what());
		}
	});

	client.connect(U(GATEWAY_URL)).then([&]() {
		ProcessBotIdentity();
	});

	client.set_close_handler([&](websocket_close_status status,
								 const utility::string_t &reason,
								 const std::error_code &code) {
		std::cout << "Bot close handler with code: " << code.value() << "\n";
	});
}

void Discord::ProcessBotIdentity() {
	websocket_outgoing_message msg;
	nJson identity;

	Intents tempInt;

	identity["op"] = OP_Type::IDENTIFY;
	identity["d"] = {
		{"token", token},
		{"intents", tempInt.GetIntents()},
		{"properties", {
#ifdef _WIN32
			{"$os", "Windows"},
#else
			{"$os", "Linux"},
#endif
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

void Discord::ProcessBotHeartbeat() {
	websocket_outgoing_message msg;
	nJson hearbeat;

	hearbeat["op"] = OP_Type::HEARTBEAT;
	hearbeat["d"] = last_signal_id;

	msg.set_utf8_message(to_string(hearbeat));
	client.send(msg);
}

void Discord::ProcessBotJson(websocket_incoming_message &msg) {
	std::string message = msg.extract_string().get();
	nJson jsonMsg = nJson::parse(message.begin(), message.end());

	int op = jsonMsg["op"];

	const nJson data = jsonMsg["d"];
}