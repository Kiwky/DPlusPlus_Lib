#include "Guild.h"
#include "Utilities.h"

Guild::Guild(const nJson &data) {
	DPlusPlus::Template::GetJson(data, "afk_timeout",					/**/ this->afk_timeout);
	DPlusPlus::Template::GetJson(data, "verification_level",			/**/ this->verification_level);
	DPlusPlus::Template::GetJson(data, "default_message_notifications",	/**/ this->default_message_notifications);
	DPlusPlus::Template::GetJson(data, "explicit_content_filter",		/**/ this->explicit_content_filter);
	DPlusPlus::Template::GetJson(data, "mfa_level",						/**/ this->mfa_level);
	DPlusPlus::Template::GetJson(data, "system_channel_flags",			/**/ this->system_channel_flags);
	DPlusPlus::Template::GetJson(data, "member_count",					/**/ this->member_count);
	DPlusPlus::Template::GetJson(data, "max_presences",					/**/ this->max_presences);
	DPlusPlus::Template::GetJson(data, "max_members",					/**/ this->max_members);
	DPlusPlus::Template::GetJson(data, "premium_tier",					/**/ this->premium_tier);
	DPlusPlus::Template::GetJson(data, "premium_subscription_count",	/**/ this->premium_subscription_count);
	DPlusPlus::Template::GetJson(data, "max_video_channel_users",		/**/ this->max_video_channel_users);
	DPlusPlus::Template::GetJson(data, "approximate_member_count",		/**/ this->approximate_member_count);
	DPlusPlus::Template::GetJson(data, "approximate_presence_count",	/**/ this->approximate_presence_count);
	DPlusPlus::Template::GetJson(data, "id",							/**/ this->id);
	DPlusPlus::Template::GetJson(data, "name",							/**/ this->name);
	DPlusPlus::Template::GetJson(data, "icon",							/**/ this->icon);
	DPlusPlus::Template::GetJson(data, "icon_hash",						/**/ this->icon_hash);
	DPlusPlus::Template::GetJson(data, "spalsh",						/**/ this->spalsh);
	DPlusPlus::Template::GetJson(data, "discovery_splash",				/**/ this->discovery_splash);
	DPlusPlus::Template::GetJson(data, "owner_id",						/**/ this->owner_id);
	DPlusPlus::Template::GetJson(data, "permissions",					/**/ this->permissions);
	DPlusPlus::Template::GetJson(data, "region",						/**/ this->region);
	DPlusPlus::Template::GetJson(data, "afk_channel_id",				/**/ this->afk_channel_id);
	DPlusPlus::Template::GetJson(data, "widget_channel_id",				/**/ this->widget_channel_id);
	DPlusPlus::Template::GetJson(data, "application_id",				/**/ this->application_id);
	DPlusPlus::Template::GetJson(data, "system_channel_id",				/**/ this->system_channel_id);
	DPlusPlus::Template::GetJson(data, "rules_channel_id",				/**/ this->rules_channel_id);
	DPlusPlus::Template::GetJson(data, "vanity_url_code",				/**/ this->vanity_url_code);
	DPlusPlus::Template::GetJson(data, "description",					/**/ this->description);
	DPlusPlus::Template::GetJson(data, "banner",						/**/ this->banner);
	DPlusPlus::Template::GetJson(data, "public_updates_channel_id",		/**/ this->public_updates_channel_id);
	DPlusPlus::Template::GetJson(data, "joined_at",						/**/ this->joined_at);
	DPlusPlus::Template::GetJson(data, "owner",							/**/ this->owner);
	DPlusPlus::Template::GetJson(data, "large",							/**/ this->large);
	DPlusPlus::Template::GetJson(data, "unavailable",					/**/ this->unavailable);

	DPlusPlus::Template::GetJsonVector(data, "roles",					/**/ this->roles);
	DPlusPlus::Template::GetJsonVector(data, "members",					/**/ this->members);
	DPlusPlus::Template::GetJsonVector(data, "channels",				/**/ this->channels);
}

Unavailable_Guild::Unavailable_Guild(const nJson &data) {
	DPlusPlus::Template::GetJson(data, "id",			/**/ this->id);
	DPlusPlus::Template::GetJson(data, "unavailable",	/**/ this->unavailable);
}