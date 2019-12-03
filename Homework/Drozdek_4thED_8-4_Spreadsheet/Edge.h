#pragma once

#include <string>
using namespace std;

struct Edge {
	// will act as elements in a list, directly related to cell position
	int item = 0;		// item to be connected
	string relation;	// descriptive string for defining
						// the connection between cells
};