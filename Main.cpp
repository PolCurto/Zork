#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

#include "Utils.h"

using namespace std;

int main()
{
	int keyCode;
	char keyValue;
	string input;
	vector<string> inputArgs;

	cout << "Welcome to Zork! \n \n";

	while (1)
	{
		keyCode = _kbhit();

		// Get the user inputs
		if (keyCode != 0)
		{
			keyValue = _getch();
			
			/*
			if (keyValue == '\b')
			{
				// Create the string with the input while there are characters
				if (input.length() > 0)
				{
					input.pop_back();
					//cout << BACKSPACE;
					cout << '\b';
					cout << " ";
					cout << '\b';
				}
			}
			*/
			if (keyValue != '\r')
			{
				// Concat the charactars in the input string
				input += keyValue;
				cout << keyValue;
			}
			else
			{
				// When enter is pressed, separates the input arguments by the blank spaces
				ParseString(input, inputArgs);
				cout << '\n';
				for (string str : inputArgs)
				{
					cout << str + " ";
				}
				cout << '\n';
			}
		}

		if (inputArgs.size() > 0)
		{
			if (inputArgs[0].compare("quit") == 0)
			{
				break;
			}
			else
			{
				cout << "Don't get the argument: " + inputArgs[0] + '\n';
			}

			inputArgs.clear();
			input = "";
			cout << "- ";
		}
	}

	cout << "You have exited the game. Thanks for playing";
}