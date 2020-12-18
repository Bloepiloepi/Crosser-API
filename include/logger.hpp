#ifndef CROSSERAPI_LOGGER_HPP
#define CROSSERAPI_LOGGER_HPP

#include <string>

class Logger {
public:
	static void info(const std::string& info);
	static void warn(const std::string& warning);
	static void error(const std::string& error);
};

#endif //CROSSERAPI_LOGGER_HPP
