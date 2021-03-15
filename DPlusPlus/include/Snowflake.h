#pragma once

#include <string>

class Snowflake {

private:
	std::string value;

public:
	Snowflake() {}
	Snowflake(const std::string &_value): value(_value) {}
	Snowflake(const char *_value): value(_value) {}

public:
	operator std::string &();

};

