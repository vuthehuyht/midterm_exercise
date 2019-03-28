#include "Logger.h"



Logger::Logger()
{
}


Logger::~Logger()
{
}

void Logger::WriteMessagse(std::string message) {
	f.open("chat.log", std::ios::in);
	if (f.fail())
		std::cerr << "Opening failed" << std::endl;
	else f << message.c_str() << std::endl;
}