#include "SSheet.h"

#include <iomanip>
using namespace std;


int row;
int col;
int* arr;

SSheet::SSheet() {
	arr = nullptr;
	this->nCells = 0;
	g = new Graph(0);
}
SSheet::SSheet(int s) {
	this->row = s;
	this->col = s;
	this->nCells = s * s;
	this->arr = new int[this->nCells];
	for (int i = 0; i < this->nCells; i++) {
		arr[i] = 0;
	}
	g = new Graph(this->nCells);
}
SSheet::SSheet(int r, int c) {
	this->row = r;
	this->col = c;
	this->nCells = r * c;
	this->arr = new int[this->nCells];
	for (int i = 0; i < this->nCells; i++) {
		arr[i] = 0;
	}
	g = new Graph(this->nCells);
}
SSheet::SSheet(int* a, int r, int c) {
	this->row = r;
	this->col = c;
	this->nCells = r * c;
	this->arr = new int[this->nCells];

	for (int i = 0; i < this->nCells; i++) {
		arr[i] = a[i];
	}
	g = new Graph(this->nCells);
}
void SSheet::printSheet() {
	int width = 5;
	cout << "   ";
	for (int i = 0; i < this->col; i++) {
		cout << "|" << setw(width) << alph[i] ;
	}
	cout << endl;
	for (int i = 0; i < this->nCells; i++) {
		if (i % this->col == 0) {
			cout << endl;
			for (int i = 0; i < this->col * 7; i++) {
				cout << "_";
			}
			cout << endl;
			cout << (i / this->col)+1 << "| ";

		}
		cout << "|";
		if (arr[i] == 0) {
			cout << setw(width) << "";
		}
		else {
			cout << setw(width) << arr[i];
		}
	}
	cout << endl << endl;
}
int SSheet::getNcells() {
	return this->nCells;
}

void SSheet::setCell(int i, int v) {
	this->arr[i] = v;
}
void SSheet::sum(int d, int i, int j) {
	this->arr[d] = this->arr[i] + this->arr[j];

	g->createEdge(d, i, "one sum component with" + j);
	g->createEdge(d, j, "one sum component with" + i);
	g->createEdge(i, d, "component of");
	g->createEdge(j, d, "component of");


}
void SSheet::difference(int d, int i, int j) {
	this->arr[d] = this->arr[i] - this->arr[j];

	g->createEdge(d, i, "one difference component with" + j);
	g->createEdge(d, j, "one difference component with" + i);
	g->createEdge(i, d, "component of");
	g->createEdge(j, d, "component of");
}