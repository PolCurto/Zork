#include <iostream>
#include <vector>
#include <conio.h>
#include <string>

#include "World.h"
#include "Utils.h"

using namespace std;

#define TICK_RATE 500

int main()
{
	int keyCode;
	char keyValue;
	string input;
	vector<string> inputArgs;

	World world;

	clock_t time = clock();
	clock_t lastTick = 0;

	cout << "Welcome to Zork! \n \n";

	while (true)
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
				inputArgs = ParseString(input, ' ');
				cout << "\n\nIntroduced command: ";
				for (string str : inputArgs)
				{
					cout << str + " ";
				}
				cout << "\n\n";
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
				if (!world.TranslateArgument(inputArgs))
				{
					cout << "The introduced command does not exist \n";
				}	
			}

			inputArgs.clear();
			input = "";
			cout << "- ";
		}

		time = clock();
		if (time - lastTick >= TICK_RATE)
		{
			//cout << time;
			lastTick = time;
			world.TickGame();
		}

		
	}

	cout << "You have exited the game. Thanks for playing";
}