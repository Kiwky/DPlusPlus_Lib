#include "Log.h"

void Log::Print(Log_Type logType, const string &message) {
	switch(logType) {
		case Error:
			cout << COLOR_RED << "[ERROR] " << COLOR_RESET << message << endl;
			break;
		case Warning:
			cout << COLOR_YELOW << "[WARNING] " << COLOR_RESET << message << endl;
			break;
		case Info:
			cout << COLOR_MAGENTA << "[INFO] " << COLOR_RESET << message << endl;
			break;
		default:
			break;
	}
}