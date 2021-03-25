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
		case OP_Type::DISPATCH:
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
					OnMessageUpdated(message);
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
				default:
				{
					break;
				}
			}

			break;
		}
		case OP_Type::HELLO:
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


