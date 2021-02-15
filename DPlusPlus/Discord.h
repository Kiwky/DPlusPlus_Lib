/*
	git ls-files | xargs cat | wc -l

	Dependencies: [AR - x86]
		BOOST			-> 1.7.0 (BUILD)
		OPENSSL			-> pe 32 biti (INSTALLER)
		CPPRESKSDK		-> din NuGet
		NLOGMANN JSON	-> GitHub (https://github.com/nlohmann/json)

	Probleme:

	TODO:
		API CALLS
*/

#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <cpprest/ws_client.h>
#include <nlohmann/json.hpp>

#include "Log.h"
#include "Utilities.h"

#include "Ready.h"
#include "Message.h"
#include "Voice.h"
#include "Role.h"

using namespace web;
using namespace web::websockets::client;
using namespace DPlusPlus::NonTemplate;
using nJson = nlohmann::json;

#define GATEWAY_URL		"wss://gateway.discord.gg/"
#define API_URL			"www.discord.gg/api/v8"

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
	std::thread hearbeat_thread;

public:
	void Start(const std::string &token);
	void ProcessBotIdentity();
	void ProcessBotHeartbeat();
	void ProcessBotJson(websocket_incoming_message &msg);

public:
	virtual void OnReady(Ready &ready);
	virtual void OnHeartBeat();

	virtual void OnMessageCreate(const Message &message);
	virtual void OnMessageUpdate(const Message &message);
	virtual void OnMessageDelete(const MessageDeleteArg &message);

	virtual void OnChannelCreate(const Channel &channel);
	virtual void OnChannelUpdate(const Channel &channel);
	virtual void OnChannelDelete(const Channel &channel);

	virtual void OnVoiceState(const Voice &voice);

	virtual void OnRoleCreate(std::string &guild_id, const Role &role);
	virtual void OnRoleUpdate(std::string &guild_id, const Role &role);
	virtual void OnRoleDelete(std::string &guild_id, const Role &role);

	virtual void OnChannelPinsUpdate(std::string &guild_id, std::string &channel_id, std::string &last_pin_time);

};

