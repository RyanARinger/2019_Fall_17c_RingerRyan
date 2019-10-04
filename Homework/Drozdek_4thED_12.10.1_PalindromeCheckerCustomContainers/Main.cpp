/*
 * File:		main.cpp
 * Author:		Ryan Ringer
 * Purpose:		
 * Created on:	
 */

#include <iostream>
#include <string>

#include "StackList.h"
#include "QueueList.h"

using namespace std;

int main(int argc, char** argv) {
	// Seed random number or initialize scanner


	// Constant Variables


	// Declare all Variables Here
	string word = "apple";
	bool isP = true;

	StackList* s = new StackList();
	QueueList* q = new QueueList();
	

	// Input or initialize values Here

	for (int i = 0; i < word.size(); i++) {
		s->push(tolower(word.at(i)));
		q->push(tolower(word.at(i)));
	}

	// Process/Calculations Here
	
	while (!s->isEmpty() && !q->isEmpty()) {
		if (s->viewTop() != q->viewFront()) {
			isP = false;
		}
		s->pop();
		q->pop();
	}
	
	// Output Located Here
	if (isP) {
		cout << word << " is a Palindrome" << endl;
	}
	else {
		cout << word << " is not a palindrome" << endl;
	}

	// Exit
	q->~QueueList();
	s->~StackList();
	return 0;
}