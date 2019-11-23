/*
 * File:		main.cpp
 * Author:		Ryan Ringer
 * Purpose:		
 * Created on:	
 */

#include <iostream>

using namespace std;

void upward(int);
void downward(int);
void both(int);

int main(int argc, char** argv) {
	// Seed random number or initialize scanner


	// Constant Variables


	// Declare all Variables Here
	int n;
	bool allowed = false;
	int choice = 0;
	// Input or initialize values Here
	while (!allowed) {
		cout << "Enter a positive number" << endl;
		cin >> n;
		if (n <= 0) {
			allowed = false;
			cout << "Invalid entry" << endl;
		}
		else {
			allowed = true;
		}
	
	}

	// Process/Calculations Here
	cout << "(1) 1 to n" << endl << endl << " or " << endl << endl << "(2) n to 1" << endl << endl
		<< " or " << endl << endl << "(3) both" << endl;

	while (choice > 3 || choice < 1) {
		cin >> choice;
		switch (choice) {
		case 1:
			cout << endl;
			upward(n);
			break;
		case 2:
			cout << endl;
			downward(n);
			break;
		case 3:
			cout << endl;
			both(n);
			break;
		default:
			cout << "Invalid Entry" << endl;
		}
	}

	// Output Located Here


	// Exit
	return 0;
}

void upward(int n) {
	if (n > 0) {
		upward(n - 1);
	}
	if (n != 0) {
		cout << n;
	}
	
}

void downward(int n) {
	if (n != 0){
		cout << n;
	}
	if (n > 0) {
		downward(n - 1);
	}
}

void both(int n) {
	if (n != 0) {
		cout << n << endl;
	}
	if (n > 0) {
		both(n-1);
	}
	if (n != 0) {
		cout << n << endl;
	}
}