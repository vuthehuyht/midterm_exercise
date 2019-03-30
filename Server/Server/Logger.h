#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include<string>
#include<fstream>
#include<iostream>
#include<ctime>
class Logger
{
public:
	void WriteMessagse(std::string message, std::string username);
	Logger();
	~Logger();
private:
	std::fstream f;
	time_t t;
};

