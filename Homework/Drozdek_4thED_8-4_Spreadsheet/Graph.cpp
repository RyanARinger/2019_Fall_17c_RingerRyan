#include "Graph.h"


Graph::Graph(int n) {
	this->nV = n; // number of vertices
	this->al = new list<Edge>[n];
}

void Graph::createEdge(int o, int d, string rel) {
	Edge temp;
	temp.item = d;
	temp.relation = rel; //for add, subtract, mult, etc. relationships/ descriptive
	al[o].push_back(temp);
}