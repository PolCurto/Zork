#include "Utils.h"

vector<string> ParseString(const string input, const char separator)
{
	vector<string> args;
	const char* str = input.c_str();
	string argument;

	do 
	{
		while (*str != separator && *str)
		{
			argument += *str;
			str++;
		}	
		args.push_back(argument);
		argument = "";
	} while (*str++);

	return args;
}