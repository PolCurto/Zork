#pragma once
#ifndef __World__
#define __World_

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class World
{
public:

	World();

	void TickGame();
	bool TranslateArgument(vector<string> argument);

private:
	vector<int> entities;
};


#endif
