Bot instance.
```c++
class Bot: public Discord {};

int main() {
	Bot bot;
	bot.Start("BOT TOKEN");
}

Class Channel:
	void SendMessage(const std::string &content, Embed *embed = nullptr);
	Message GetMessage(const Snowflake &message_id);
	std::vector<Message> GetMessages(int limit = 100);
	Channel ModifyChannel(Channel &new_channel);
	Message ModifyMessage(const Snowflake &message_id, Message &new_message);
	void ModifyChannelPermissions(/*const Overwrite overwrite*/);
	void DeleteChannelPermission(/*const Overwrite overwrite*/);
	void DeleteMessage(const Snowflake &message_id);
	void DeleteMessageBulk(std::vector<Message> message_list);
	void DeleteChannel();
	void DeleteUserReaction(const Snowflake &message_id, const std::string &emoji);
	void DeleteReaction(const Snowflake &message_id, const std::string &emoji);
	void DeleteAllReactions(const Snowflake &message_id);
	void CreateReaction(const Snowflake &message_id, const std::string &emoji);
	std::vector<User> GetReactions(const Snowflake &message_id, const std::string &emoji);
	std::vector<Invite> GetInvites();
	Invite CreateInvite(int max_age, int max_uses, bool temporary, const std::string target_user = "");
	std::vector<Message> GetPinnedMessages();
	void AddPinnedMessage(const Snowflake &message_id);
	void DeletePinnedMessage(const Snowflake &message_id);
	
Class Guild
	std::vector<Emoji> ListEmoji();
	Emoji GetEmoji(const std::string &emoji_id);
	Emoji CreateEmoji(const std::string &name, /*const Image &image*/ std::vector<Snowflake> *roles = nullptr);
	Emoji ModifyEmoji(const std::string &name, std::vector<Snowflake> *roles = nullptr);
	void DeleteEmoji(const std::string &emoji_id);

	
```
