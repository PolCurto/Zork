#include "Utils.h"

void ParseString(string& input, vector<string>& args)
{
	const char* str = input.c_str();

	do
	{
		const char* begin = str;

		while (*str != ' ' && *str)
			str++;

		args.push_back(string(begin, str));
	} while (0 != *str++);
}