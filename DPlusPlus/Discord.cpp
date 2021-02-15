#include "Discord.h"

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
}

void Discord::ProcessBotIdentity() {
	websocket_outgoing_message msg;
	nJson identity;

	identity["op"] = OP_Type::IDENTIFY;
	identity["d"] = {
		{"token", token},
		{"properties", {
			{"$os", "Windows"},
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
#pragma region DISPATCH [1]
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
					break;
				}
				case hash_string("GUILD_UPDATE"):
				{
					break;
				}
				case hash_string("GUILD_DELETE"):
				{
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
					const Role role(data["role"]);
					std::string guild_id = data["guild_id"];

					// Call virtual.
					OnRoleDelete(guild_id, role);
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
					break;
				}
				case hash_string("GUILD_MEMBER_ADD"):
				{
					break;
				}
				case hash_string("GUILD_MEMBER_UPDATE"):
				{
					break;
				}
				case hash_string("GUILD_MEMBER_REMOVE"):
				{
					break;
				}
				case hash_string("GUILD_BAN_ADD"):
				{
					break;
				}
				case hash_string("GUILD_BAN_REMOVE"):
				{
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
					break;
				}
				case hash_string("MESSAGE_REACTION_REMOVE"):
				{
					break;
				}
				case hash_string("MESSAGE_REACTION_REMOVE_ALL"):
				{
					break;
				}
				case hash_string("MESSAGE_REACTION_REMOVE_EMOJI"):
				{
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
#pragma endregion
#pragma region HELLO [10]
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
#pragma endregion
#pragma region HEARTBEAT_ACK [11]
		case OP_Type::HEARTBACK_ACK:
		{
			// Call  virtual.
			OnHeartBeat();
		}
#pragma endregion
#pragma region DEFAULT
		default:
			break;
#pragma endregion
	}
}
