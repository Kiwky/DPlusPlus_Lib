#include "Log.h"

void Log::Print(Log_Type logType, const std::string &message) {
	switch(logType) {
		case Error:
			std::cout << COLOR_RED << "[ERROR] " << COLOR_RESET << message << std::endl;
			break;
		case Warning:
			std::cout << COLOR_YELOW << "[WARNING] " << COLOR_RESET << message << std::endl;
			break;
		case Info:
			std::cout << COLOR_MAGENTA << "[INFO] " << COLOR_RESET << message << std::endl;
			break;
		case Succes:
			std::cout << COLOR_GREEN << "[SUCCES] " << COLOR_RESET << message << std::endl;
			break;
		default:
			break;
	}
}