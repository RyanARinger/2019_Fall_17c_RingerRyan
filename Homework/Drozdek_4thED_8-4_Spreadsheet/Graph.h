#pragma once

#include "Edge.h"

#include<string>
#include<list>
using namespace std;

class Graph {
private:
	int nV;
	

public: 
	list<Edge>* al; // adjacency lists
	Graph(int);

	void createEdge(int, int, string);
};