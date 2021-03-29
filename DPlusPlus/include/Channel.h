#pragma once

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

#include "Utilities.h"
#include "User.h"
#include "Message.h"
#include "Embed.h"
#include "Invite.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

enum class Channel_Type {
	GUILD_TEXT = 0,
	DM,
	GUILD_VOICE,
	GROUP_DM,
	GUILD_CATEGORY,
	GUILD_NEWS,
	GUILD_STORE
};

class Channel {

public:
	Snowflake id;
	Snowflake guild_id;
	Snowflake last_message_id;
	int position;
	int bitrate;
	int user_limit;
	Channel_Type type;
	std::string name;
	std::string topic;
	std::string icon;
	bool nsfw;
	// vector<overwrite> permission_overwrites;

public:
	Channel() {}
	Channel(const Snowflake channel_id);
	Channel(const nJson &data);

public:
	void ToJson(nJson &j);

	// Sends a message to this channel.
	// Requires the SEND_MESSAGES permission.
	void SendMessage(const std::string &content, Embed *embed = nullptr);

	// Returns a specific message.
	// Requires the VIEW_CHANNEL permission.
	Message GetMessage(const Snowflake &message_id);

	// Returns a list of 'limit' messages.
	// Requires the VIEW_CHANNEL permission.
	std::vector<Message> GetMessages(int limit = 100);

	// Update a channel's settings.
	// Requires the MANAGE_CHANNELS permission.
	Channel ModifyChannel(Channel &new_channel);

	// Edit a previously sent message.
	// Requires the MANAGE_MESSAGES permission. 
	Message ModifyMessage(const Snowflake &message_id, Message &new_message);

	// TODO
	// Edit the channel permission overwrites for a user or role in a channel.
	// Requires the MANAGE_ROLES permission.
	void ModifyChannelPermissions(/*const Overwrite overwrite*/);

	// TODO
	// Delete a channel permission overwrite for a user or role in a channel.
	// Requires the MANAGE_ROLES permission.
	void DeleteChannelPermission(/*const Overwrite overwrite*/);

	// Delete a message.
	// Requires the MANAGE_MESSAGES permission. 
	void DeleteMessage(const Snowflake &message_id);

	// Delete multiple messages in a single request. 
	// Requires the MANAGE_MESSAGES permission. 
	void DeleteMessageBulk(std::vector<Message> message_list);

	// Delete a channel, or close a private message.
	// Requires the VIEW_CHANNEL permission.
	void DeleteChannel();

	// TODO
	// Deletes another user's reaction.
	// Requires the MANAGE_MESSAGES permission.
	void DeleteUserReaction(const Snowflake &message_id, const std::string &emoji);

	// TODO
	// Deletes all the reactions for a given emoji on a message. 
	// Requires the MANAGE_MESSAGES permission.
	void DeleteReaction(const Snowflake &message_id, const std::string &emoji);

	// Deletes all reactions on a message.
	// Requires the MANAGE_MESSAGES permission.
	void DeleteAllReactions(const Snowflake &message_id);

	// TODO (Nu functioneaza).
	// If nobody else has reacted to the message using this emoji.
	// Requires the ADD_REACTIONS permission.
	void CreateReaction(const Snowflake &message_id, const std::string &emoji);

	// TODO (Nu functioneaza cred, nu e verificat)
	// Get a list of users that reacted with this emoji.
	std::vector<User> GetReactions(const Snowflake &message_id, const std::string &emoji);

	// Returns a list of invite objects (with invite metadata) for the channel.
	// Requires the MANAGE_CHANNELS permission.
	std::vector<Invite> GetInvites();

	// TODO
	// Create a new invite object for the channel.
	// Requires the CREATE_INSTANT_INVITE permission.
	Invite CreateInvite(int max_age, int max_uses, bool temporary, const std::string &target_user = "");

	// TODO
	// Returns all pinned messages in the channel.
	std::vector<Message> GetPinnedMessages();

	// TODO
	// Pin a message in a channel.
	// Requires the MANAGE_MESSAGES permission.
	void AddPinnedMessage(const Snowflake &message_id);

	// TODO
	// Delete a pinned message in a channel. 
	// Requires the MANAGE_MESSAGES permission.
	void DeletePinnedMessage(const Snowflake &message_id);
};
