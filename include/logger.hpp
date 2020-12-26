#ifndef CROSSERAPI_LOGGER_HPP
#define CROSSERAPI_LOGGER_HPP

#include <string>

class Logger {
public:
	[[maybe_unused]] static const std::string info;
	[[maybe_unused]] static const std::string warning;
	[[maybe_unused]] static const std::string error;
};

#endif //CROSSERAPI_LOGGER_HPP
