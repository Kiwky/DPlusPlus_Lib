#pragma once

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

#include "Utilities.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

class Embed_Footer {};

class Embed_Image {};

class Embed_Thumbnail {};

class Embed_Video {};

class Embed_Provider {};

class Embed_Author {};

class Embed_Field {

};

class Embed {

public:
	int color;
	std::string title;
	std::string type;
	std::string description;
	std::string url;
	std::string timestamp;
	Embed_Footer footer;
	Embed_Image image;
	Embed_Thumbnail thumbnail;
	Embed_Video video;
	Embed_Provider provider;
	Embed_Author author;
	std::vector<nJson> fields;

public:
	void ToJson(nJson &j) {
		j = nJson{
			{"title",		/**/ title},
			{"type",		/**/ type},
			{"description",	/**/ description},
			{"url",			/**/ url},
			{"timestamp",	/**/ timestamp},
			{"color",		/**/ color}
		};

		for(auto iter = fields.begin(); iter != fields.end(); ++iter) {
			j["fields"].push_back(*iter);
		}
	}

	void AddField(const std::string &name, const std::string &value, bool _inlineField) {
		nJson newField;

		newField["name"] = name;
		newField["value"] = value;
		newField["inline"] = _inlineField;

		fields.push_back(newField);
	}

};
