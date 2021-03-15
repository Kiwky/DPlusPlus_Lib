#include "Log.h"

void Log::Print(Log_Type logType, const std::string &message) {

#ifdef _WIN32
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
#endif 

	switch(logType) {
		case Error:
#if _WIN32
			SetConsoleTextAttribute(hConsole, COLOR_RED);
			std::cout << "[ERROR] ";
			SetConsoleTextAttribute(hConsole, COLOR_RESET);
			std::cout << message << std::endl;
#else
			std::cout << COLOR_RED << "[ERROR] " << COLOR_RESET << message << std::endl;
#endif
			break;
		case Warning:
#if _WIN32
			SetConsoleTextAttribute(hConsole, COLOR_YELOW);
			std::cout << "[WARNING] ";
			SetConsoleTextAttribute(hConsole, COLOR_RESET);
			std::cout << message << std::endl;
#else
			std::cout << COLOR_YELOW << "[WARNING] " << COLOR_RESET << message << std::endl;
#endif
			break;
		case Info:
#if _WIN32
			SetConsoleTextAttribute(hConsole, COLOR_MAGENTA);
			std::cout << "[INFO] ";
			SetConsoleTextAttribute(hConsole, COLOR_RESET);
			std::cout << message << std::endl;
#else
			std::cout << COLOR_MAGENTA << "[INFO] " << COLOR_RESET << message << std::endl;
#endif
			break;
		case Succes:
#if _WIN32
			SetConsoleTextAttribute(hConsole, COLOR_GREEN);
			std::cout << "[SUCCES] ";
			SetConsoleTextAttribute(hConsole, COLOR_RESET);
			std::cout << message << std::endl;
#else
			std::cout << COLOR_GREEN << "[SUCCES] " << COLOR_RESET << message << std::endl;
#endif
			break;
		default:
			break;
	}
}