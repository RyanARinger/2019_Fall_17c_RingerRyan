/*
 * File:		main.cpp
 * Author:		Ryan Ringer
 * Purpose:		main function implementation
 * Created on:	September 4th, 2019
 */

#include <iostream>
#include "Fraction.h"

using namespace std;

// This project contains a class (Fraction) that defines adding, subtracting,
// multiplying, and dividing fractions by overloading standard operators for
// these operations. It also contains a function member for reducing factors and overloaded
// I/O operators to input and output fractions

int main(int argc, char** argv) {
	// Seed random number or initialize scanner


	// Constant Variables


	// Declare all Variables Here
	Fraction* f1 = new Fraction();

		
	// Input or initialize values Here
	cin >> *f1;

	// Process/Calculations Here


	// Output Located Here
	cout << *f1;

	// Exit
	delete f1;
	return 0;
}