/*
 * File:		main.cpp
 * Author:		Ryan Ringer
 * Purpose:		Rudimentary Spreadsheet
 * Created on:	November 25, 2019
 */

#include <iostream>
#include <list>
#include <sstream>

#include "SSheet.h"
#include "Edge.h"
using namespace std;

void sumCells(SSheet*, int, int);
void subtractCells(SSheet*, int, int);
void setCell(SSheet*, int, int);

int main(int argc, char** argv) {
	// Seed random number or initialize scanner


	// Constant Variables
	const int NROWS = 20;
	const int NCOLS = 8;
	const int NCELLS = NROWS * NCOLS;

	// Declare all Variables Here
	SSheet* sheet;
	enum colChoice {a,b,c,d,f,g,h};
	int choice;

	// Input or initialize values Here
	sheet = new SSheet( NROWS, NCOLS);
	sheet->printSheet();

	// Process/Calculations Here
	cout << "enter task: " << endl << "(1)add" << endl << "(2)subtract"
		<< endl << "(3)define" << endl;;
	cin >> choice;
	switch (choice) {
	case(1):
		sumCells(sheet, NROWS, NCOLS);
		break;
	case(2):
		subtractCells(sheet, NROWS, NCOLS);
		break;
	case(3):
		setCell(sheet, NROWS, NCOLS);
		break;
	default:
		cout << "INVALID OPTION" << endl;
	}
	// Output Located Here



	// Exit
	delete sheet;
	return 0;
}
void sumCells(SSheet* s,int r, int c) {
	int cell1, cell2, destination, ssInt, rowsIn;
	string input;
	cout << "Enter target cell" << endl;
	cin >> input;
	rowsIn = (input.at(0) - 97);			// letter as first character
	//for (int i = 1; i < input.length(); i++) {	
	//	proc.at(i - 1) = input.at(i);		// removing the first char
	//}		
	input.erase(0, 1);
	stringstream stream(input);
	stream >> ssInt;						// streaming column number to int
	destination = ((ssInt-1)*c) + rowsIn;

	cout << "Enter first cell to be summed" << endl;
	cin >> input;
	rowsIn = (input.at(0) - 97);			
	input.erase(0, 1);
	stream >> ssInt;						
	cell1 = ((ssInt - 1) * c) + rowsIn;

	cout << "Enter second cell to be summed" << endl;
	cin >> input;
	rowsIn = (input.at(0) - 97);
	input.erase(0, 1);

	stream >> ssInt;
	cell2 = ((ssInt - 1) * c) + rowsIn;
	
	s->sum(destination, cell1, cell2);
	cout << "Completed" << endl;

}

// repeated sequence for subtraction
void subtractCells(SSheet* s, int r, int c) {
	int cell1, cell2, destination, ssInt, rowsIn;
	string input;
	cout << "Enter target cell" << endl;
	cin >> input;
	rowsIn = (input.at(0) - 97);			// letter as first character
	input.erase(0, 1);
	stringstream stream(input);
	stream >> ssInt;						// streaming column number to int
	destination = ((ssInt - 1) * c) + rowsIn;

	cout << "Enter first cell to be subtracted" << endl;
	cin >> input;
	rowsIn = (input.at(0) - 97);
	input.erase(0, 1);
	stream >> ssInt;
	cell1 = ((ssInt - 1) * c) + rowsIn;

	cout << "Enter second cell to be subtracted" << endl;
	cin >> input;
	rowsIn = (input.at(0) - 97);
	input.erase(0, 1);
	stream >> ssInt;
	cell2 = ((ssInt - 1) * c) + rowsIn;

	s->difference(destination, cell1, cell2);
	cout << "Completed" << endl;
}

void setCell(SSheet* s,int r, int c) {
	int destination, ssInt, rowsIn;
	int data;
	string input, proc;

	cout << "Enter target cell" << endl;
	cin >> input;
	rowsIn = (input.at(0) - 97);			// letter as first character
	input.erase(0, 1);
	stringstream stream(input);
	stream >> ssInt;						// streaming column number to int
	destination = ((ssInt - 1) * c) + rowsIn;

	cout << "Enter integer value to be stored" << endl;
	cin >> data;

	s->setCell(destination, data);
	cout << "Completed" << endl;
}