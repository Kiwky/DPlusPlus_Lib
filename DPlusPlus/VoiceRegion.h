#pragma once

#include <string>
#include <nlohmann/json.hpp>

#include "Utilities.h"

using nJson = nlohmann::json;
using namespace DPlusPlus;

class VoiceRegion {

public:
	std::string id;
	std::string name;
	bool vip;
	bool optimal;
	bool deprecated;
	bool custom;

public:
	VoiceRegion() {}
	VoiceRegion(const nJson &data);

};

