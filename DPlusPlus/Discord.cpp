#include "Discord.h"
#include "Intents.h"

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
			Log::Print(Error, "Message handler error [CATCH]: " + (std::string)e.what());
		}
	});

	client.connect(U(GATEWAY_URL)).then([&]() {
		ProcessBotIdentity();
	});

	client.set_close_handler([&](websocket_close_status status,
								 const utility::string_t &reason,
								 const std::error_code &code) {
		std::cout << "Bot close handler. [" << code.value() << "] \n";
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
	hearbeat["d"] = lastSRec;

	msg.set_utf8_message(to_string(hearbeat));
	client.send(msg);
}

void Discord::ProcessBotJson(websocket_incoming_message &msg) {
	std::string message = msg.extract_string().get();
	nJson jsonMsg = nJson::parse(message.begin(), message.end());

	//std::cout << message << std::endl;
	int op = jsonMsg["op"];

	// Data (json string).
	const nJson data = jsonMsg["d"];

	switch(op) {
		case OP_Type::DISPATCH:
		{
			const std::string type = jsonMsg["t"];	// Message type.
			lastSRec = jsonMsg["s"];				// Last signal/event id received.

			//Log::Print(Info, "Event received: " + type);
			switch(hash_string(type.c_str())) {
				case hash_string("READY"):
				{
					Log::Print(Succes, "Gateway connection successfull.");

					Ready readyData(data);
					this->session_id = readyData.session_id;

					// Call virtual.
					OnReady(readyData);
					break;
				}
				/*case hash_string("RESUMED"):
				{
					break;
				}*/
				case hash_string("GUILD_CREATE"):
				{
					Guild guild(data);

					// Call virtual.
					OnGuildCreate(guild);
					break;
				}
				case hash_string("GUILD_UPDATE"):
				{
					Guild guild(data);

					// Call virtual.
					OnGuildUpdate(guild);
					break;
				}
				case hash_string("GUILD_DELETE"):
				{
					Unavailable_Guild guild(data);

					// Call virtual.
					OnGuildDelete(guild);
					break;
				}
				case hash_string("GUILD_ROLE_CREATE"):
				{
					const Role role(data["role"]);
					std::string guild_id = data["guild_id"];

					// Call virtual.
					OnRoleCreate(guild_id, role);
					break;
				}
				case hash_string("GUILD_ROLE_UPDATE"):
				{
					const Role role(data["role"]);
					std::string guild_id = data["guild_id"];

					// Call virtual.
					OnRoleUpdate(guild_id, role);
					break;
				}
				case hash_string("GUILD_ROLE_DELETE"):
				{
					//const Role role(data);
					//std::string guild_id = data["guild_id"];

					//// Call virtual.
					//OnRoleDelete(guild_id, role);
					break;
				}
				case hash_string("CHANNEL_CREATE"):
				{
					Channel channel(data);

					// Call virtual.
					OnChannelCreate(channel);
					break;
				}
				case hash_string("CHANNEL_UPDATE"):
				{
					Channel channel(data);

					// Call virtual.
					OnChannelUpdate(channel);
					break;
				}
				case hash_string("CHANNEL_DELETE"):
				{
					Channel channel(data);

					// Call virtual.
					OnChannelDelete(channel);
					break;
				}
				case hash_string("CHANNEL_PINS_UPDATE"):
				{
					std::string guild_id, channel_id, last_pin_timestamp;

					DPlusPlus::Template::GetJson(data, "guild_id",				/**/ guild_id);
					DPlusPlus::Template::GetJson(data, "channel_id",			/**/ channel_id);
					DPlusPlus::Template::GetJson(data, "last_pin_timestamp",	/**/ last_pin_timestamp);

					// Call virtual.
					OnChannelPinsUpdate(guild_id, channel_id, last_pin_timestamp);
					break;
				}
				case hash_string("GUILD_MEMBER_ADD"):
				{
					Member member(data);
					std::string guild_id;

					DPlusPlus::Template::GetJson(data, "guild_id", guild_id);

					// Call virtual.
					OnMemberAdd(guild_id, member);
					break;
				}
				case hash_string("GUILD_MEMBER_REMOVE"):
				{
					User user(data["user"]);
					std::string guild_id;

					DPlusPlus::Template::GetJson(data, "guild_id", guild_id);

					// Call virtual.
					OnMemberRemove(guild_id, user);
					break;
				}
				case hash_string("GUILD_MEMBER_UPDATE"):
				{
					User user(data["user"]);
					std::string guild_id, nick, joined_at;

					DPlusPlus::Template::GetJson(data, "guild_id",	/**/ guild_id);
					DPlusPlus::Template::GetJson(data, "nick",		/**/ nick);
					DPlusPlus::Template::GetJson(data, "joined_at", /**/ joined_at);

					// Call virtual.
					OnMemberUpdate(guild_id, user, nick, joined_at);
					break;
				}
				case hash_string("GUILD_BAN_ADD"):
				{
					User user(data["user"]);
					std::string guild_id;

					DPlusPlus::Template::GetJson(data, "guild_id", guild_id);

					// Call virtual.
					OnMemberBan(guild_id, user);
					break;
				}
				case hash_string("GUILD_BAN_REMOVE"):
				{
					User user(data["user"]);
					std::string guild_id;

					DPlusPlus::Template::GetJson(data, "guild_id", guild_id);

					// Call virtual.
					OnMemberUnBan(guild_id, user);
					break;
				}
				case hash_string("GUILD_EMOJIS_UPDATE"):
				{
					break;
				}
				case hash_string("GUILD_INTEGRATIONS_UPDATE"):
				{
					break;
				}
				case hash_string("WEBHOOKS_UPDATE"):
				{
					std::string guild_id, channel_id;

					DPlusPlus::Template::GetJson(data, "guild_id",		/**/ guild_id);
					DPlusPlus::Template::GetJson(data, "channel_id",	/**/ channel_id);

					// Call virtual.
					OnWebHooksUpdate(guild_id, channel_id);
					break;
				}
				case hash_string("INVITE_CREATE"):
				{
					break;
				}
				case hash_string("INVITE_DELETE"):
				{
					break;
				}
				case hash_string("VOICE_STATE_UPDATE"):
				{
					const Voice voice(data);

					// Call virtual.
					OnVoiceState(voice);
					break;
				}
				case hash_string("PRESENCE_UPDATE"):
				{
					// TODO
					break;
				}
				case hash_string("MESSAGE_CREATE"):
				{
					const Message message(data);

					// Call virtual.
					OnMessageCreate(message);
					break;
				}
				case hash_string("MESSAGE_UPDATE"):
				{
					const Message message(data);

					// Call virtual.
					OnMessageUpdate(message);
					break;
				}
				case hash_string("MESSAGE_DELETE"):
				{
					const MessageDeleteArg message(data);

					// Call virtual.
					OnMessageDelete(message);
					break;
				}
				case hash_string("MESSAGE_DELETE_BULK"):
				{
					break;
				}
				case hash_string("MESSAGE_REACTION_ADD"):
				{
					Member member;
					std::string user_id, channel_id, message_id, guild_id;

					if(data.contains("member")) {
						member = Member(data["member"]);
					}

					DPlusPlus::Template::GetJson(data, "user_id",		/**/ user_id);
					DPlusPlus::Template::GetJson(data, "channel_id",	/**/ channel_id);
					DPlusPlus::Template::GetJson(data, "message_id",	/**/ message_id);
					DPlusPlus::Template::GetJson(data, "guild_id",		/**/ guild_id);

					// Call virtual.
					OnReactionAdd(member, user_id, guild_id, channel_id, message_id);
					break;
				}
				case hash_string("MESSAGE_REACTION_REMOVE"):
				{
					std::string user_id, channel_id, message_id, guild_id;

					DPlusPlus::Template::GetJson(data, "user_id",		/**/ user_id);
					DPlusPlus::Template::GetJson(data, "channel_id",	/**/ channel_id);
					DPlusPlus::Template::GetJson(data, "message_id",	/**/ message_id);
					DPlusPlus::Template::GetJson(data, "guild_id",		/**/ guild_id);

					// Call virtual.
					OnReactionRemove(user_id, guild_id, channel_id, message_id);
					break;
				}
				case hash_string("TYPING_START"):
				{
					break;
				}
				default:
				{
					break;
				}
			}
			break;
		}
		case OP_Type::HELLO:
		{
			isReady = true;
			heartbeat_interval = data["heartbeat_interval"];

			hearbeat_thread = std::thread([&]() {
				while(true) {
					try {
						std::this_thread::sleep_for(std::chrono::milliseconds(heartbeat_interval));
						ProcessBotHeartbeat();
					} catch(const std::exception &e) {
						Log::Print(Error, "Heartbeat thread error [CATCH]: " + (std::string)e.what());
					}
				}
			});

			break;
		}
		case OP_Type::HEARTBACK_ACK:
		{
			// Call  virtual.
			OnHeartBeat();
		}
		default:
			break;
	}
}
