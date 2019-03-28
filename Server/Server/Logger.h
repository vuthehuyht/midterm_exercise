#pragma once
#include<string.h>
#include<fstream>
#include<iostream>
class Logger
{
public:
	void WriteMessagse(std::string message);
	Logger();
	~Logger();
private:
	std::fstream f;


};

