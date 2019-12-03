#pragma once
#include "Graph.h"

#include <string>
#include <iostream>

using namespace std;


class SSheet {
private:
	int row;
	int col;
	int* arr;
	int nCells;
	char alph[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
		'o','p','q','r','s','t','u','v','w','x','y','z' };
	Graph* g;

public:
	SSheet();
	SSheet(int);
	SSheet(int, int);
	SSheet(int*, int, int);
	void printSheet();
	int getNcells();
	void setCell(int, int);
	void sum(int, int, int);
	void difference(int, int, int);
};