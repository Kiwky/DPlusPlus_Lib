/*
	Dependencies:
		BOOST			-> 1.7.0 (BUILD)
		OPENSSL			-> pe 32 biti (INSTALLER)
		CPPRESKSDK		-> din NuGet
		NLOGMANN JSON	-> GitHub (https://github.com/nlohmann/json)
*/

#pragma once

#include <iostream>
#include <string>
#include <cpprest/ws_client.h>
#include <nlohmann/json.hpp>

#include "Log.h"

using namespace web;
using namespace web::websockets::client;
using nJson = nlohmann::json;

enum OP_Type {
	DISPATCH				/**/ = 0,
	HEARTBEAT				/**/ = 1,
	IDENTIFY				/**/ = 2,
	STATUS_UPDATE			/**/ = 3,
	VOICE_STATE_UPDATE		/**/ = 4,
	VOICE_SERVER_PING		/**/ = 5,
	RESUME					/**/ = 6,
	RECONECT				/**/ = 7,
	REQUEST_GUILD_MEMBERS	/**/ = 8,
	INVALID_SESSION			/**/ = 9,
	HELLO					/**/ = 10,
	HEARTBACK_ACK			/**/ = 11
};

class Discord {

private:
	websocket_callback_client client;
	std::string token;
	std::string session_id;
	int lastSRec;
	int heartbeat_interval;
	bool isReady;

public:
	void Start(const std::string &token);
	void ProcessBotIdentity();

	void ProcessBotJson(websocket_incoming_message &msg) {
		std::string message = msg.extract_string().get();
		nJson jsonMsg = nJson::parse(message.begin(), message.end());

		std::cout << message << std::endl;

		int op = jsonMsg["op"];

		switch(op) {
			case OP_Type::DISPATCH:
			{
				const std::string type = jsonMsg["t"];	// Message type.
				const nJson data = jsonMsg["d"];		// Data (json string).
				lastSRec = jsonMsg["s"];				// Last signal/event id received.

				Log::Print(Info, "Event received: " + type);

				// Switch each event type name.
				break;
			}
			default:
				break;
		}
	}


};

