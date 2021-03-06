#include "Discord.h"
#include "Intents.h"

std::string Discord::token;

void Discord::Start(const std::string &token) {
	if(token.length() == 0) {
		Log::Print(Error, "No token has been set.");
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
			Log::Print(Error, "Message handler error [CATCH]: " + (std::string)e.what());
		}
	});

	client.connect(U(GATEWAY_URL)).then([&]() {
		ProcessBotIdentity();
	});

	client.set_close_handler([&](websocket_close_status status,
								 const utility::string_t &reason,
								 const std::error_code &code) {
		std::wcout << reason << "\n";
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
	nJson jsonMsg = nJson::parse(message);

	int op = jsonMsg["op"];				// OP_Type
	const nJson data = jsonMsg["d"];	// Json data

	switch(op) {
		case (int)OP_Type::DISPATCH:
		{
			const std::string type = jsonMsg["t"];	// Message type.
			last_signal_id = jsonMsg["s"];			// Last signal/event id received.

			switch(hash_string(type.c_str())) {
				case hash_string("READY"):
				{
					Ready ready(data);
					this->session_id = ready.session_id;

					// Call virtual function.
					OnReady(ready);
					break;
				}
				case hash_string("GUILD_CREATE"):
				{
					Guild guild(data);

					// Call virtual function.
					OnGuildCreated(guild);
					break;
				}
				case hash_string("GUILD_UPDATE"):
				{
					Guild guild(data);

					// Call virtual function.
					OnGuildUpdate(guild);
					break;
				}
				// TODO GUILD_DELETE
				case  hash_string("GUILD_ROLE_CREATE"):
				{
					Role role(data["role"]);
					std::string guild_id;

					GetJson(data, "guild_id", guild_id);

					// Call virtual function.
					OnRoleCreated(guild_id, role);
					break;
				}
				case  hash_string("GUILD_ROLE_UPDATE"):
				{
					Role role(data["role"]);
					std::string guild_id;

					GetJson(data, "guild_id", guild_id);

					// Call virtual function.
					OnRoleUpdate(guild_id, role);
					break;
				}
				case  hash_string("GUILD_ROLE_DELETE"):
				{
					std::string guild_id, role_id;

					GetJson(data, "guild_id", guild_id);
					GetJson(data, "role_id", role_id);

					// Call virtual function.
					OnRoleDeleted(guild_id, role_id);
					break;
				}
				case hash_string("CHANNEL_CREATE"):
				{
					Channel channel(data);

					// Call virtual function.
					OnChannelCreated(channel);
					break;
				}
				case hash_string("CHANNEL_UPDATE"):
				{
					Channel channel(data);

					// Call virtual function.
					OnChannelUpdate(channel);
					break;

				}
				case hash_string("CHANNEL_DELETE"):
				{
					Channel channel(data);

					// Call virtual function.
					OnChannelDeleted(channel);
					break;
				}
				case hash_string("CHANNEL_PINS_UPDATE"):
				{
					std::string guild_id, channel_id;

					GetJson(data, "guild_id",	/**/ guild_id);
					GetJson(data, "channel_id",	/**/ channel_id);

					// Call virtual function.
					OnChannelPinsUpdate(guild_id, channel_id);
					break;
				}
				case hash_string("MESSAGE_CREATE"):
				{
					Message message(data);

					// Call virtual function.
					OnMessageCreated(message);
					break;
				}
				case hash_string("MESSAGE_UPDATE"):
				{
					Message message(data);

					// Call virtual function.
					OnMessageUpdate(message);
					break;
				}
				case hash_string("MESSAGE_DELETE"):
				{
					MessageDelete message(data);

					// Call virtual function.
					OnMessageDeleted(message);
					break;
				}
				case hash_string("MESSAGE_DELETE_BULK"):
				{
					MessageDeleteBulk message(data);

					// Call virtual function.
					OnMessageDeletedBulk(message);
					break;
				}
				case hash_string("MESSAGE_REACTION_ADD"):
				{
					Member member;
					std::string channel_id, message_id, guild_id;

					if(data.contains("member")) {
						member = Member(data["member"]);
					}

					GetJson(data, "channel_id",		/**/ channel_id);
					GetJson(data, "message_id",		/**/ message_id);
					GetJson(data, "guild_id",		/**/ guild_id);

					// Call virtual function.
					OnMessageReactionAdd(member, guild_id, channel_id, message_id);
					break;
				}
				case hash_string("MESSAGE_REACTION_REMOVE"):
				{
					User user = User(data["user_id"].get<std::string>());
					std::string channel_id, message_id, guild_id;

					GetJson(data, "channel_id",		/**/ channel_id);
					GetJson(data, "message_id",		/**/ message_id);
					GetJson(data, "guild_id",		/**/ guild_id);

					// Call virtual function.
					OnMessageReactionDeleted(user, guild_id, channel_id, message_id);
					break;
				}
				case hash_string("MESSAGE_REACTION_REMOVE_ALL"):
				{
					std::string channel_id, message_id, guild_id;

					GetJson(data, "channel_id",		/**/ channel_id);
					GetJson(data, "message_id",		/**/ message_id);
					GetJson(data, "guild_id",		/**/ guild_id);

					// Call virtual function.
					OnMessageReactionDeletedAll(guild_id, channel_id, message_id);
					break;
				}
				case hash_string("MESSAGE_REACTION_REMOVE_EMOJI"):
				{
					Emoji emoji(data["emoji"]);
					std::string channel_id, message_id, guild_id;

					GetJson(data, "channel_id",		/**/ channel_id);
					GetJson(data, "message_id",		/**/ message_id);
					GetJson(data, "guild_id",		/**/ guild_id);

					// Call virtual function.
					OnMessageReactionRemoveEmoji(emoji, guild_id, channel_id, message_id);
					break;
				}
				case hash_string("VOICE_STATE_UPDATE"):
				{
					Voice voice(data);

					// Call virtual function.
					OnVoiceStateUpdate(voice);
					break;
				}
				case hash_string("INVITE_CREATE"):
				{
					Invite invite(data);

					// Call virtual function.
					OnInviteCreated(invite);
					break;
				}
				case hash_string("INVITE_DELETE"):
				{
					std::string channel_id, guild_id, code;

					GetJson(data, "channel_id",	/**/ channel_id);
					GetJson(data, "guild_id",	/**/ guild_id);
					GetJson(data, "code",		/**/ code);

					// Call virtual function.
					OnInviteDeleted(guild_id, channel_id, code);
					break;
				}
				default:
				{
					break;
				}
			}
			break;
		}
		case (int)OP_Type::HELLO:
		{
			heartbeat_interval = data["heartbeat_interval"];
			is_ready = true;

			heartbeat_thread = std::thread([&]() {
				while(true) {
					try {
						std::this_thread::sleep_for(std::chrono::milliseconds(heartbeat_interval));
						ProcessBotHeartbeat();
					}
					catch(const std::exception &e) {
						Log::Print(Error, "Heartbeat thread error [CATCH]: " + (std::string)e.what());
					}
				}
			});

			break;
		}
	}
}

// TODO TIMESTAMP AUTOMAT
void Discord::ModifyPresence(const std::string &name, const std::string &status_type) {
	websocket_outgoing_message msg;
	nJson status;

	status["op"] = OP_Type::STATUS_UPDATE;
	status["d"] = {
		{"since", 1616783423771},
		{"activities", {{
			{"name", name},
			{"type", 0},
		}}},
		{"status", status_type},
		{"afk", false}
	};

	msg.set_utf8_message(to_string(status));
	client.send(msg);
}
