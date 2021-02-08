#pragma once

#include <string>
#include <nlohmann/json.hpp>

using nJson = nlohmann::json;

class Guild {
};

class Unavailable_Guild {

public:
	std::string id;

public:
	Unavailable_Guild() {}
	Unavailable_Guild(const nJson &data);

};