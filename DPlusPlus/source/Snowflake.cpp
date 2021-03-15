#include "Snowflake.h"

Snowflake::operator std::string &() {
	return value;
}
