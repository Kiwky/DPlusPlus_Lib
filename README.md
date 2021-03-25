Bot instance.
```c++
class Bot: public Discord {};

int main() {
	Bot bot;
	bot.Start("BOT TOKEN");
}

Virtuals:
	virtual void OnReady(const Ready &ready);
	virtual void OnMessageCreated(const Message &message);
	virtual void OnMessageUpdated(const Message &message);
	virtual void OnMessageDeleted(const MessageDelete &message);
	virtual void OnMessageDeletedBulk(const MessageDeleteBulk &message);
	virtual void OnMessageReactionAdd(const Member &member, const Snowflake &guild_id, const Snowflake &channel_id, const Snowflake &message_id);


Class Channel:
	Ctor: Chanel(channel_id);
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
	
Class Guild:
	Ctor: Guild(guild_id);
	std::vector<Emoji> ListEmoji();
	Emoji GetEmoji(const std::string &emoji_id);
	Emoji CreateEmoji(const std::string &name, /*const Image &image*/ std::vector<Snowflake> *roles = nullptr);
	Emoji ModifyEmoji(const std::string &name, std::vector<Snowflake> *roles = nullptr);
	void DeleteEmoji(const std::string &emoji_id);
	GuildPreview GetGuildPreview();
	Guild ModifyGuild(
		const std::string &name, const std::string &region,
		int verification_level, int default_message_notifications, int explicit_content_filter, int afk_timeout,
		const Snowflake &afk_channel_id
		/*,Image splash, Image banner*/
	);
	void DeleteGuild();
	std::vector<Channel> GetChannels();
	Channel CreateChannel(/*Lista parametrii*/);
	void ModifyChannel(const Snowflake &channel_id, int new_position);
	Member GetMember(const Snowflake &user_id);
	std::vector<Member> GetMembers();
	Member ModifyMember(const Snowflake &user_id, const std::string &new_nick, std::vector<Snowflake> roles, bool mute, bool deaf, const Snowflake &channel_id);
	void ModifyMemberNickname(const Snowflake &user_id, const std::string &new_nick);
	void AddMemberRole(const Snowflake &user_id, const Snowflake &role_id);
	void RemoveMemberRole(const Snowflake &user_id, const Snowflake &role_id);
	void RemoveMemberRole(const Snowflake &user_id);
	std::vector<Ban> GetGuildBans();
	Ban GetGuildBan(const Snowflake &user_id);
	void Ban(const Snowflake &user_id, const std::string reason = "", int delete_message_days = 0);
	void RemoveBan(const Snowflake &user_id);
	std::vector<Role> GetRoles();
	Role CreateRole(const std::string &name, const std::string permissions, int color, bool hoist, bool mentionable);
 	std::vector<Role> ModifyRolePosition(const Snowflake &role_id, int position);
	Role ModifyRolePosition(const Snowflake &role_id, const std::string &name, const std::string &permissions, int color, bool hoist, bool mentionable);
	void DeleteRole(const Snowflake &role_id);
	void GetGuildPruneRole(int days, std::vector<Snowflake> include_roles);
	void BeginGuildPrune(int days, bool compute_prune_count, std::vector<Snowflake> include_roles);
	std::vector<VoiceRegion> GetGuildVoiceRegions();
	std::vector<Invite> GetInvites();
 	std::vector<Integration> GetIntegrations();
	void CreateIntegration(const std::string &type, const Snowflake &id);
	void ModifyIntegration(const Snowflake &integrastion_id, int expire_behavior, int expire_grace_period, int enable_emoticons);
	void DeleteIntegration(const Snowflake &integrastion_id);
	void SyncIntegration(const Snowflake &integrastion_id);

Class User:
	Ctor: User(user_id);
	User ModifyBot(const std::string username /*, Image image*/);
	Guild GetUserGuilds();
	void LeaveGuild();

Class Embed:
	void AddField(const std::string &name, const std::string &value, bool _inlineField);

Class Invite:
	Ctor: Invite(invite_id);
	void Delete();

```
