#pragma once

#include <vector>
#include <nlohmann/json.hpp>

using nJson = nlohmann::json;

class Ready {

public:
	uint32_t gateway_version;
	std::string session_id;

public:
	Ready() {}
	Ready(const nJson &data);

};
