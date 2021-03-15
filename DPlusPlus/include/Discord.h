#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <cpprest/ws_client.h>
#include <nlohmann/json.hpp>

#include "Utilities.h"
#include "Ready.h"

using namespace DPlusPlus::NonTemplate;
using namespace web;
using namespace web::websockets::client;
using nJson = nlohmann::json;

#define GATEWAY_URL	"wss://gateway.discord.gg/"
#define API_URL		"www.discord.gg/api/v8"

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
	int last_signal_id;
	int heartbeat_interval;
	bool is_ready;
	std::string token;
	std::string session_id;
	std::thread heartbeat_thread;

public:
	/* Start the bot instance. */
	void Start(const std::string &token);

	/* Try to connect with bot information. */
	void ProcessBotIdentity();

	/* Send bot information every `heartbeat_interval` ms. */
	void ProcessBotHeartbeat();

	/* Process the json received. */
	void ProcessBotJson(websocket_incoming_message &msg);

protected:
	/* The ready event is dispatched when a client has completed the initial handshake with the gateway */
	virtual void OnReady(Ready &ready);

};
