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
#include "Emoji.h"	
#include "Voice.h"	

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

// Base color. Or convert other hex color to dec.
enum Colors {
	DEFAULT				/**/ = 0,
	AQUA				/**/ = 1752220,
	DARK_AQUA			/**/ = 1146986,
	DARK_GREEN			/**/ = 2067276,
	BLUE				/**/ = 3447003,
	DARK_BLUE			/**/ = 2123412,
	PURPLE				/**/ = 10181046,
	DARK_PURPLE			/**/ = 7419530,
	LUMINOUS_VIVID_PINK /**/ = 15277667,
	DARK_VIVID_PINK		/**/ = 11342935,
	GOLD				/**/ = 15844367,
	DARK_GOLD			/**/ = 12745742,
	ORANGE				/**/ = 15105570,
	DARK_ORANGE			/**/ = 11027200,
	RED					/**/ = 15158332,
	DARK_RED			/**/ = 10038562,
	GREY				/**/ = 9807270,
	DARK_GREY			/**/ = 9936031,
	DARKER_GREY			/**/ = 8359053,
	LIGHT_GREY			/**/ = 12370112,
	NAVY				/**/ = 3426654,
	DARK_NAVY			/**/ = 2899536,
	YELLOW				/**/ = 16776960,
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
	// Start the bot instance. 
	void Start(const std::string &token);

	// Try to connect with bot information. 
	void ProcessBotIdentity();

	// Send bot information every `heartbeat_interval` ms. 
	void ProcessBotHeartbeat();

	// Process the json received. 
	void ProcessBotJson(websocket_incoming_message &msg);

	// Update bot status activity.
	// Status: online / dnd / idle / invisible / offline.
	void ModifyPresence(const std::string &name, const std::string &status_type = "online");

protected:
	// The ready event is dispatched when a client has completed the initial handshake with the gateway 
	virtual void OnReady(const Ready &ready);

	// Sent when a message is created. 
	virtual void OnMessageCreated(const Message &message);

	// Sent when a message is updated. 
	virtual void OnMessageUpdated(const Message &message);

	// Sent when a message is deleted. 
	virtual void OnMessageDeleted(const MessageDelete &message);

	// Sent when multiple messages are deleted at once. 
	virtual void OnMessageDeletedBulk(const MessageDeleteBulk &message);

	// Sent when a user adds a reaction to a message. 
	virtual void OnMessageReactionAdd(const Member &member, const Snowflake &guild_id, const Snowflake &channel_id, const Snowflake &message_id);

	// Sent when a user removes a reaction from a message. 
	virtual void OnMessageReactionDeleted(const User &user, const Snowflake &guild_id, const Snowflake &channel_id, const Snowflake &message_id);

	// Sent when a user explicitly removes all reactions from a message. 
	virtual void OnMessageReactionDeletedAll(const Snowflake &guild_id, const Snowflake &channel_id, const Snowflake &message_id);

	// Sent when a bot removes all instances of a given emoji from the reactions of a message.
	virtual void OnMessageReactionRemoveEmoji(const Emoji &emoji, const Snowflake &guild_id, const Snowflake &channel_id, const Snowflake &message_id);

	// Sent when someone joins/leaves/moves voice channels.
	virtual void OnVoiceStateUpdate(const Voice &voice);
};
