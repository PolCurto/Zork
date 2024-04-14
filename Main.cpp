#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include <ctime>

#include "World.h"
#include "Utils.h"

using namespace std;

#define TICK_RATE 250

int main()
{
	int keyCode;
	char keyValue;
	string input;
	vector<string> inputArgs;

	World world;

	clock_t timer = clock();
	clock_t lastTick = 0;

	// Seed the random numbers
	srand((unsigned int)time(NULL));

	cout << "Welcome to Zork! \n \n";
	cout << "- ";

	while (true)
	{
		keyCode = _kbhit();

		// Get the user inputs
		if (keyCode != 0)
		{
			keyValue = _getch();
			
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
				cout << "\n\n";
			}
		}

		if (inputArgs.size() > 0)
		{
			if (inputArgs[0].compare("quit") == 0)	// Quits the game
			{
				cout << "You have quit the game. Thanks for playing\n";
				break;
			}
			else
			{
				if (!world.TranslateArgument(inputArgs))
				{
					cout << "The introduced command does not exist \n\n";
				}	
			}

			inputArgs.clear();
			input = "";
			cout << "\n- ";
		}

		timer = clock();
		if (timer - lastTick >= TICK_RATE)
		{
			//cout << time;
			lastTick = timer;
			world.TickGame();
		}

		if (world.PlayerIsDead())
		{
			cout << "Game over\n";
			break;
		}
		else if (world.PlayerIsLord())
		{
			cout << "Congratulations, you became the lord of a new era!\nThanks for playing\n";
			break;
		}
	}
}