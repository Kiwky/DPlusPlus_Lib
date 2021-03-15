#pragma once

#include <vector>
#include <nlohmann/json.hpp>

using nJson = nlohmann::json;

class Ready {

public:
	int gateway_version;
	std::string session_id;

public:
	Ready() {}
	Ready(const nJson &data);

};
