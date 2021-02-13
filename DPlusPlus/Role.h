#pragma once

#include <string>
#include <nlohmann/json.hpp>

using nJson = nlohmann::json;

class Role {

public:
	int color;
	int position;
	uint64_t permissions;
	std::string id;
	std::string name;
	bool hoist;
	bool managed;
	bool mentionable;


public:
	Role() {}
	Role(const nJson &data);

};

