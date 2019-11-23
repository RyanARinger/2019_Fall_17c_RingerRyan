/*
 * File:		main.cpp
 * Author:		Ryan Ringer
 * Purpose:		
 * Created on:	
 */

#include <iostream>

using namespace std;

void reverse();

int main(int argc, char** argv) {
	// Seed random number or initialize scanner


	// Constant Variables


	// Declare all Variables Here


	// Input or initialize values Here


	// Process/Calculations Here
	cout << "Type anything and press [ENTER]" << endl;
	reverse();

	// Output Located Here


	// Exit
	return 0;
}

void reverse() {
	int ch;

	ch = cin.get();

	if (ch != '\n') {
		reverse();
	}

	cout.put(ch);
}