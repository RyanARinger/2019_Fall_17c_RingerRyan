#pragma once

#include <string>

using namespace std;

struct PassengerNode {
	PassengerNode* p;
	PassengerNode* n;
	string name;
};