#include "Utils.h"

vector<string> ParseString(const string input, const char separator)
{
	vector<string> args;
	const char* str = input.c_str();

	do
	{
		const char* begin = str;

		while (*str != separator && *str)
			str++;

		args.push_back(string(begin, str));
	} while (0 != *str++);

	return args;
}