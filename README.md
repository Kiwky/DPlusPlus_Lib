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
	void DeleteMessage(const Snowflake &message_id);
	void DeleteMessageBulk(std::vector<Message> message_list);
	void DeleteChannel();
	void DeleteReaction(const Snowflake &message_id, const std : string & emoji);
	void DeleteAllReactions(const Snowflake &message_id);
	void CreateReaction(const Snowflake &message_id, const std::string &emoji);
	std::vector<Invite> GetInvites();
```
