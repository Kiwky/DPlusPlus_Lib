#include "Guild.h"

Guild::Guild(const nJson &data) {
	GetJson(data, "id",								/**/ id);
	GetJson(data, "owner_id",						/**/ owner_id);
	GetJson(data, "afk_channel_id",					/**/ afk_channel_id);
	GetJson(data, "widget_channel_id",				/**/ widget_channel_id);
	GetJson(data, "application_id",					/**/ application_id);
	GetJson(data, "system_channel_id",				/**/ system_channel_id);
	GetJson(data, "rules_channel_id",				/**/ rules_channel_id);
	GetJson(data, "public_updates_channel_id",		/**/ public_updates_channel_id);
	GetJson(data, "afk_timeout",					/**/ afk_timeout);
	GetJson(data, "verification_level",				/**/ verification_level);
	GetJson(data, "default_message_notifications",	/**/ default_message_notifications);
	GetJson(data, "expliciti_content_filter",		/**/ expliciti_content_filter);
	GetJson(data, "mfa_level",						/**/ mfa_level);
	GetJson(data, "system_channel_flags",			/**/ system_channel_flags);
	GetJson(data, "member_count",					/**/ member_count);
	GetJson(data, "max_presences",					/**/ max_presences);
	GetJson(data, "max_members",					/**/ max_members);
	GetJson(data, "premium_tier",					/**/ premium_tier);
	GetJson(data, "premium_subscription_count",		/**/ premium_subscription_count);
	GetJson(data, "max_video_channel_users",		/**/ max_video_channel_users);
	GetJson(data, "afk_timeout",					/**/ afk_timeout);
	GetJson(data, "approximate_member_count",		/**/ approximate_member_count);
	GetJson(data, "approximate_presence_count",		/**/ approximate_presence_count);
	GetJson(data, "owner",							/**/ owner);
	GetJson(data, "widget_enabled",					/**/ widget_enabled);
	GetJson(data, "large",							/**/ large);
	GetJson(data, "unavailable",					/**/ unavailable);
	GetJson(data, "name",							/**/ name);
	GetJson(data, "icon",							/**/ icon);
	GetJson(data, "icon_hash",						/**/ icon_hash);
	GetJson(data, "splash",							/**/ splash);
	GetJson(data, "discovery_splash",				/**/ discovery_splash);
	GetJson(data, "permissions",					/**/ permissions);
	GetJson(data, "regions",						/**/ regions);
	GetJson(data, "joined_at",						/**/ joined_at);
	GetJson(data, "vanity_url_code",				/**/ vanity_url_code);
	GetJson(data, "description",					/**/ description);
	GetJson(data, "banner",							/**/ banner);
	GetJson(data, "preferred_locale",				/**/ preferred_locale);

	GetJsonVector(data, "channels",					/**/ channels);
	GetJsonVector(data, "members",					/**/ members);
	GetJsonVector(data, "emojis",					/**/ emojis);

}