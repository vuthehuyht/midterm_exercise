#include "Logger.h"



Logger::Logger()
{
}


Logger::~Logger()
{
}

void Logger::WriteMessagse(std::string message, std::string username) {
	char str[32]{};
	t = time(0);
	struct tm* time_info = localtime(&t);
	f.open("chat.log", std::ios::app);
	if (f.fail())
		std::cerr << "Opening failed" << std::endl;
	else f<< time_info->tm_year + 1900 << "-" << time_info->tm_mon + 1 << "-" <<time_info->tm_mday << " " << time_info->tm_hour<< ":" <<time_info->tm_min <<":" << time_info->tm_sec+ 1 << " " << username << " " << message << std::endl;
}