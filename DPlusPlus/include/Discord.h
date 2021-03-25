/**
 *	TODO:
 *		> OnMessageDeletedBulk modificare parametrii:
 *			> De exemplu (std::vector<Snowflake> ids, Snowflake channel_id, Snowflake guild_id);
 */

#pragma once

#include <iostream>
#include <string>
#include <thread>
#include <cpprest/ws_client.h>
#include <nlohmann/json.hpp>
#include <cpprest/http_client.h>

#include "Utilities.h"
#include "Log.h"
#include "Ready.h"
#include "Message.h"
#include "Member.h"
#include "Channel.h"	

using namespace DPlusPlus;
using namespace web;
using namespace web::http;
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
	int last_signal_id;
	int heartbeat_interval;
	bool is_ready;
	std::string session_id;
	std::thread heartbeat_thread;

public:
	static std::string token;

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
	virtual void OnReady(const Ready &ready);

	/* Sent when a message is created. */
	virtual void OnMessageCreated(const Message &message);

	/* Sent when a message is updated. */
	virtual void OnMessageUpdated(const Message &message);

	/* Sent when a message is deleted. */
	virtual void OnMessageDeleted(const MessageDelete &message);

	/* Sent when multiple messages are deleted at once. */
	virtual void OnMessageDeletedBulk(const MessageDeleteBulk &message);

	/* Sent when a user adds a reaction to a message. */
	virtual void OnMessageReactionAdd(const Member &member, const Snowflake &guild_id, const Snowflake &channel_id, const Snowflake &message_id);
	
	/* Sent when a user removes a reaction from a message. */
	virtual void OnMessageReactionDeleted(const User &user, const Snowflake &guild_id, const Snowflake &channel_id, const Snowflake &message_id);
};
