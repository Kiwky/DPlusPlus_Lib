/*
	Dependencies:
		BOOST			-> 1.7.0 (BUILD)
		OPENSSL			-> pe 32 biti (INSTALLER)
		CPPRESKSDK		-> din NuGet
		NLOGMANN JSON	-> GitHub (https://github.com/nlohmann/json)
*/

#pragma once

#include <iostream>
#include <string>
#include <cpprest/ws_client.h>
#include <nlohmann/json.hpp>

#include "Log.h"

using nJson = nlohmann::json;
using namespace web;
using namespace web::websockets::client;

class Discord {

private:
	websocket_callback_client client;
	std::string token;
	std::string session_id;
	int lastSRec;
	int heartbeat_interval;
	bool isReady;

public:
	void Start(const std::string &token) {
		if(token.length() == 0) {
			Log::Print(Error, "No token has been set.");
			return;
		}
	}

};

