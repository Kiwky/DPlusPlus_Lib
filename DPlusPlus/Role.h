#pragma once

#include <string>
#include <nlohmann/json.hpp>

using nJson = nlohmann::json;

class Role {

public:
	int color;
	int position;
	std::string id;
	std::string name;
	std::string permissions;
	bool hoist;
	bool managed;
	bool mentionable;


public:
	Role() {}
	Role(const nJson &data);

};

