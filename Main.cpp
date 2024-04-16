#include <iostream>
#include <vector>
#include <conio.h>
#include <string>
#include <ctime>

#include "World.h"

using namespace std;

int main()
{
	int tickRate = 250;
	int keyCode;
	char keyValue;
	string input;
	vector<string> inputArgs;

	World world;

	clock_t timer = clock();
	clock_t lastTick = 0;

	srand((unsigned int)time(NULL));    // Seed the random numbers

	cout << "Welcome! \n";
	cout << "This is a small text-based game. In order to complete it, find and use the item called Star.\n";
	cout <<	"Good luck!\n\n";
	cout << "- ";

	while (true)
	{
		keyCode = _kbhit();

		// Get the user inputs
		if (keyCode != 0)
		{
			keyValue = _getch();
			
			if (keyValue == '\r')
			{
				// When enter is pressed, separates the input arguments by the blank spaces
				char separator = ' ';
				size_t initialPos = 0;
				size_t pos = input.find(separator);

				while (pos != string::npos) {
					inputArgs.push_back(input.substr(initialPos, pos - initialPos));
					initialPos = pos + 1;

					pos = input.find(separator, initialPos);
				}

				inputArgs.push_back(input.substr(initialPos, min(pos, input.size()) - initialPos));

				cout << "\n\n";
			}
			else
			{
				// Concat the charactars in the input string
				input += keyValue;
				cout << keyValue;
			}
		}

		if (inputArgs.size() > 0)
		{
			if (inputArgs[0].compare("quit") == 0)	// Quits the game
			{
				cout << "You have quit the game. Thanks for playing\nPress any key to close the window... ";
				break;
			}
			else
			{
				if (!world.TranslateArgument(inputArgs))
				{
					cout << "The introduced command does not exist \n\n";
				}	
			}

			cout << "\n- ";
			inputArgs.clear();
			input = "";
		}

		timer = clock();

		if (timer - lastTick >= tickRate)
		{
			lastTick = timer;
			world.TickGame();
		}

		if (world.PlayerIsDead())
		{
			cout << "Game over\nPress any key to close the window...";
			break;
		}
		else if (world.PlayerIsLord())
		{
			cout << "Congratulations, you became the lord of a new era!\nThanks for playing\nPress any key to close the window...";
			break;
		}
	}

	while (true)
	{
		if (_kbhit() != 0)	// Close the game when any key is pressed
			break;
	}

	return 0;
}