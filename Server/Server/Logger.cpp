#include "Logger.h"



Logger::Logger()
{
}


Logger::~Logger()
{
}

void Logger::WriteMessagse(std::string message, std::string username, std::string time) {
	f.open("chat.log", std::ios::app);
	if (f.fail())
		std::cerr << "Opening file failed!" << std::endl;
	else
		f << time << " " << username << " " << message << std::endl;
}