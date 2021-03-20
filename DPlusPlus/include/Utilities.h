#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <cpprest/ws_client.h>
#include <nlohmann/json.hpp>
#include <cpprest/http_client.h>

using namespace web;
using namespace web::http;
using namespace web::websockets::client;
using nJson = nlohmann::json;

namespace DPlusPlus {

#define GATEWAY_URL	"wss://gateway.discord.gg/"
#define API_URL		"https://discord.com/api/v8"

	typedef std::string Snowflake;

	constexpr unsigned int hash_string(const char *str, int h = 0) {
		return !str[h] ? 5381 : (hash_string(str, h + 1) * 33) ^ str[h];
	}

	/* Get json value, return default if key does not exist. */
	template <typename T>
	void GetJson(const nJson &j, const char *key, T &val) {
		if(j.contains(key) == false || j.at(key).is_null()) {
			val = T{};
		}
		else {
			val = j.value(key, T{});
		}
	}

	/* Get json array, return empty vectory. */
	template <typename T>
	void GetJsonVector(const nJson &j, const char *key, std::vector<T> &val) {
		if(j.contains(key) == false || j.at(key).is_null()) {
			val = std::vector<T>();
		}
		else {
			const nJson &tempJson = j.at(key);
			val.resize(tempJson.size());
			copy(
				j[key].begin(),
				j[key].end(),
				val.begin()
			);
		}
	}

	nJson API_Call(const std::string &url, method api_method, const std::string &jsonObject = "");
}
