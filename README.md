Bot instance.
```c++
class Bot: public Discord {};

int main() {
	Bot bot;
	bot.Start("BOT TOKEN");
}

Message:
```
	> void SendMessage(const std::string &content, Embed *embed = nullptr);
	> Message GetMessage(const Snowflake &message_id);
	> std::vector<Message> GetMessages(int limit = 100);
```
```
