/*
 * File:		main.cpp
 * Author:		Ryan Ringer
 * Purpose:		
 * Created on:	
 */

#include <iostream>
#include <string>

#include "PassengerNode.h"

using namespace std;

PassengerNode* reserve(PassengerNode*, string);
PassengerNode* cancel(PassengerNode*, string);
void check(PassengerNode*, string);

int main(int argc, char** argv) {
	// Seed random number
	// Constant Variables
	const int S = 10;

	// Declare all Variables Here
	PassengerNode* head;
	PassengerNode* next;
	PassengerNode* temp;
	string nameStr;
	int choice = 0;
	string nameChoice;


	// Input or initialize values Here
	next = new PassengerNode;
	next->p = nullptr;
	temp = next;
	head = next;
	string names[S]{ "Ryan", "Conner", "Nathalie", "Stanley",
	"Kevihn", "Daniel", "John", "Luigi", "Rodrigo", "Josh" };

	for (int i = 0; i < S; i++) {
		for (int j = 0; j < S; j++) {
			if (names[i] < names[j]) {
				nameStr = names[i];
				names[i] = names[j];
				names[j] = nameStr;
			}
		}
	}

	// Process/Calculations Here



	for (int i = 0; i < S; i++) {
		next->name = names[i];
		next = new PassengerNode;
		next->p = temp;
		temp->n = next;
		temp = temp->n;
	}
	next->n = nullptr;

	cout << "1. Reserve a ticket" << endl;
	cout << "2. Cancel Reservation" << endl;
	cout << "3. Check a Reservation" << endl;


	while (choice < 1 || choice > 3) {
		cin >> choice;
		switch (choice) {
		case 1:
			cout << "Who is the reservation for?: ";
			cin >> nameChoice;
			head = reserve(head, nameChoice);
			cout << "Reservation made!" << endl;
			break;

		case 2:
			cout << "Please enter the name for the reservation you wish to cancel: ";
			cin >> nameChoice;
			head = cancel(head, nameChoice);
			cout << "Reservation Cancelled " << endl;
			break;

		case 3:
			cout << "Enter the name you wish to search: ";
			cin >> nameChoice;
			check(head, nameChoice);
			break;

		default:
			cout << "INVALID CHOICE" << endl;
		}
	}

	// Output Located Here


	bool done = false;
	cout << "Flight Passenger Manifest: " << endl;
	cout << "___________________________" << endl;
	next = head;
	while (!done) {
		cout << next->name << endl;
		if (next->n == nullptr) {
			done = true;
		}
		else {
			next = next->n;
		}
	}

	

	// Exit
	return 0;
}

PassengerNode* reserve(PassengerNode* head, string nm) {
	PassengerNode* node = new PassengerNode;
	PassengerNode* temp = head;
	bool done = false;
		
	node->name = nm;

	while (!done) {
		if (temp->n == nullptr) {
				node->p = temp;
				node->n = nullptr;
				temp->n = node;
				done = true;
		}
		else if (temp->name > nm) {
			if (temp->p == nullptr) {
				head = node;
				node->p = nullptr;
				node->n = temp;
				temp->p = node;
			}
			else {
				temp = temp->p;
				node->n = temp->n;
				temp->n = node;
				node->p = temp;
			}
			done = true;
		}
		else {
			temp = temp->n;
		}
	}
	return head;
}

PassengerNode* cancel(PassengerNode* head, string nm) {
	PassengerNode* temp = head;
	bool done = false;

	if (temp->name == nm) {
		head = temp->n;
		done = true;
	}

	while (!done) {
		if (temp->name == nm) {

			temp->p->n = temp->n;
			temp->n->p = temp->p;
			done = true;
		}
		else {
			if (temp->n == nullptr) {
				done = true;
			}
			else {
				temp = temp->n;
			}
		}
	}
	return head;
}

void check(PassengerNode* head, string nm) {
	PassengerNode* temp = head;
	string tempName;
	bool done = false;
	bool exists = false;
	while (!done) {
		tempName = temp->name;
		if (tempName == nm) {
			exists = true;
			done = true;
		}
		else if (temp->n == nullptr) {
			done = true;
		}
		else {
			temp = temp->n;
		}
	}

	if (exists) {
		cout << "A reservation exists on this flight for " << nm << endl;
	}
	else {
		cout << "A reservation does not exist on this flight for " << nm << endl;
	}
}