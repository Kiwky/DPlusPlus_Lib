#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

using nJson = nlohmann::json;

namespace DPlusPlus {

	namespace Template {

		template <typename T>
		void GetJson(const nJson &j, const char *key, T &val) {
			if(j.contains(key) == false || j.at(key).is_null()) {
				val = T{};
			}
			else {
				val = j.value(key, T{});
			}
		}

	}

	namespace NonTemplate {

		constexpr unsigned int hash_string(const char *str, int h = 0) {
			return !str[h] ? 5381 : (hash_string(str, h + 1) * 33) ^ str[h];
		}

	}

}
