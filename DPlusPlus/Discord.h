/*
	git ls-files | xargs cat | wc -l

	Dependencies: [AR - x86]
		BOOST			-> 1.7.0 (BUILD)
		OPENSSL			-> pe 32 biti (INSTALLER)
		CPPRESKSDK		-> NuGet
		NLOHMANN JSON	-> NuGet

	Probleme:

	TODO:
		API CALLS
		OnReactionAdd adaugare parametru 'Emoji`
		OnReactionRemove adaugare parametru 'Emoji`
		Guild.h nu are `emojis`
		Guild.h nu are `features`
		Guild.h nu are `welcome_screen`
		Guild.h nu are `voice_states`
		Guild.h nu are `presences`
		OnMemberPresenceUpdate nu are toti parametrii.

	RMD:
		INVITE_CREATE nu are toti parametrii (are tot ce e important), nu este o problema dar de stiut.
		GUILD_EMOJIS_UPDATE stearsa temporar din `Discord.h`
		GUILD_INTEGRATIONS_UPDATE stearsa temporar din `Discord.h`
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
	/* The ready event is dispatched when a client has completed the initial handshake with the gateway */
	virtual void OnReady(Ready &ready);

	/* The client should begin sending Opcode 1 Heartbeat payloads every heartbeat_interval milliseconds */
	virtual void OnHeartBeat();

	/* Sent when a new user joins a guild. */
	virtual void OnMemberAdd(const std::string guild_id, const Member &member);

	/* Sent when a user is removed from a guild (leave/kick/ban). */
	virtual void OnMemberRemove(const std::string guild_id, const User &user);

	/* Sent when a guild member is updated. This will also fire when the user object of a guild member changes. */
	virtual void OnMemberUpdate(const std::string guild_id, const User &user, const std::string &nick, const std::string &joined_at);

	/* Sent when a user is unbanned from a guild. */
	virtual void OnMemberBan(const std::string guild_id, const User &user);

	/* Sent when a user is unbanned from a guild. */
	virtual void OnMemberUnBan(const std::string guild_id, const User &user);

	/* A user's presence is their current state on a guild. This event is sent when a user's presence or info, such as name or avatar, is updated. */
	virtual void OnMemberPresenceUpdate(const User &user, const std::string &guild_id, const std::string &status);

	/* Sent when a message is created. */
	virtual void OnMessageCreate(const Message &message);

	/* Sent when a message is updated. */
	virtual void OnMessageUpdate(const Message &message);

	/* Sent when a message is deleted. */
	virtual void OnMessageDelete(const MessageDeleteArg &message);

	/* Sent when a new guild channel is created, relevant to the current user. */
	virtual void OnChannelCreate(const Channel &channel);

	/* Sent when a channel is updated. */
	virtual void OnChannelUpdate(const Channel &channel);

	/* Sent when a channel relevant to the current user is deleted. */
	virtual void OnChannelDelete(const Channel &channel);

	/*
		This event can be sent in three different scenarios:
		1. When a user (bot) is initially connecting. Guilds that are unavailable due to an outage will send a Guild Delete event.
		2. When a Guild becomes available again to the client.
		3. When the current user joins a new Guild.
	*/
	virtual void OnGuildCreate(const Guild &guild);

	/* Sent when a guild is updated. */
	virtual void OnGuildUpdate(const Guild &guild);

	/* Sent when a guild becomes or was already unavailable due to an outage, or when the user leaves or is removed from a guild. */
	virtual void OnGuildDelete(const Unavailable_Guild &guild);

	/* Sent when someone joins/leaves/moves voice channels. */
	virtual void OnVoiceStateUpdate(const Voice &voice);

	/* Sent when a guild role is created. */
	virtual void OnRoleCreate(const std::string &guild_id, const Role &role);

	/* Sent when a guild role is updated. */
	virtual void OnRoleUpdate(const std::string &guild_id, const Role &role);

	/* Sent when a guild role is deleted. */
	virtual void OnRoleDelete(const std::string &guild_id, const std::string &role_id);

	/* Sent when a message is pinned or unpinned in a text channel. */
	virtual void OnChannelPinsUpdate(const std::string &guild_id, const std::string &channel_id, const std::string &last_pin_time);

	/* Sent when a user adds a reaction to a message. */
	virtual void OnReactionAdd(const Member &member, const std::string &user_id, const std::string &guild_id, const std::string &channel_id, const std::string &message_id);

	/* Sent when a user removes a reaction from a message. */
	virtual void OnReactionRemove(const std::string &user_id, const std::string &guild_id, const std::string &channel_id, const std::string &message_id);

	/* Sent when a guild channel's webhook is created, updated, or deleted. */
	virtual void OnWebHooksUpdate(const std::string &guild_id, const std::string &channel_id);

	/* Sent when a new invite to a channel is created. */
	virtual void OnInviteCreate(const User &user, const std::string &guild_id, const std::string &channel_id, const std::string &code, int max_use, bool temporary);
	
	/* Sent when an invite is deleted. */
	virtual void OnInviteDelete(const std::string &guild_id, const std::string &channel_id, const std::string &code);
};

