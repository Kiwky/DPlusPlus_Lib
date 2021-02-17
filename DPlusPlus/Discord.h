/*
	git ls-files | xargs cat | wc -l

	Dependencies: [AR - x86]
		BOOST			-> 1.7.0 (BUILD)
		OPENSSL			-> pe 32 biti (INSTALLER)
		CPPRESKSDK		-> NuGet
		NLOHMANN JSON	-> NuGet

	Probleme:
		Guild role delete argumente gresite. [Bloc comentat complet]

	TODO:
		API CALLS
		OnReactionAdd adaugare parametru 'Emoji`
		OnReactionRemove adaugare parametru 'Emoji`
		Guild.h nu are `emojis`
		Guild.h nu are `features`
		Guild.h nu are `welcome_screen`
		Guild.h nu are `voice_states`
		Guild.h nu are `presences`
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
#include "Member.h"
#include "User.h"

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

protected:
	virtual void OnReady(Ready &ready);
	virtual void OnHeartBeat();

	virtual void OnMemberAdd(const std::string guild_id, const Member &member);
	virtual void OnMemberRemove(const std::string guild_id, const User &user);
	virtual void OnMemberUpdate(const std::string guild_id, const User &user, const std::string &nick, const std::string &joined_at);
	virtual void OnMemberBan(const std::string guild_id, const User &user);
	virtual void OnMemberUnBan(const std::string guild_id, const User &user);

	virtual void OnMessageCreate(const Message &message);
	virtual void OnMessageUpdate(const Message &message);
	virtual void OnMessageDelete(const MessageDeleteArg &message);

	virtual void OnChannelCreate(const Channel &channel);
	virtual void OnChannelUpdate(const Channel &channel);
	virtual void OnChannelDelete(const Channel &channel);

	virtual void OnGuildCreate(const Guild &guild);
	virtual void OnGuildUpdate(const Guild &guild);
	virtual void OnGuildDelete(const Unavailable_Guild &guild);

	virtual void OnVoiceState(const Voice &voice);

	virtual void OnRoleCreate(const std::string &guild_id, const Role &role);
	virtual void OnRoleUpdate(const std::string &guild_id, const Role &role);
	virtual void OnRoleDelete(const std::string &guild_id, const Role &role);

	virtual void OnChannelPinsUpdate(const std::string &guild_id, const std::string &channel_id, const std::string &last_pin_time);

	virtual void OnReactionAdd(const Member &member, const std::string &user_id, const std::string &guild_id, const std::string &channel_id, const std::string &message_id);
	virtual void OnReactionRemove(const std::string &user_id, const std::string &guild_id, const std::string &channel_id, const std::string &message_id);

	virtual void OnWebHooksUpdate(const std::string &guild_id, const std::string &channel_id);
};

