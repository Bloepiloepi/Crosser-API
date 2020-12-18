#include <iostream>
#include "logger.hpp"

void Logger::info(const std::string& info) {
	std::cout << "[INFO]: " << info << std::endl;
}

void Logger::warn(const std::string& warning) {
	std::cerr << "[WARNING]: " << warning << std::endl;
}

void Logger::error(const std::string& error) {
	std::cerr << "[ERROR]: " << error << std::endl;
}
