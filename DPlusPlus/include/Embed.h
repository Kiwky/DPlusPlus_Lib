#pragma once

#include <vector>
#include <string>
#include <nlohmann/json.hpp>

#include "Utilities.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

enum Embe_Type {
	RICH = 0,
	IMAGE,
	VIDEO,
	GIFV,
	ARTICLE,
	LINK
};

class Embed_Footer {

public:
	std::string text;
	std::string icon_url;
	std::string proxy_icon_url;

public:
	void ToJson(nJson &j);

};

class Embed_Image {

public:
	std::string url;
	std::string proxy_url;
	std::string height;
	std::string width;

public:
	void ToJson(nJson &j);

};

class Embed_Thumbnail {

public:
	std::string url;
	std::string proxy_url;
	std::string height;
	std::string width;

public:
	void ToJson(nJson &j);

};

class Embed_Video {

public:
	std::string url;
	std::string proxy_url;
	std::string height;
	std::string width;

public:
	void ToJson(nJson &j);

};

class Embed_Provider {

public:
	std::string name;
	std::string url;

public:
	void ToJson(nJson &j);

};

class Embed_Author {

public:
	std::string name;
	std::string url;
	std::string icon_url;
	std::string proxy_icon_url;

public:
	void ToJson(nJson &j);

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
	void ToJson(nJson &j);
	void AddField(const std::string &name, const std::string &value, bool _inlineField);

};
