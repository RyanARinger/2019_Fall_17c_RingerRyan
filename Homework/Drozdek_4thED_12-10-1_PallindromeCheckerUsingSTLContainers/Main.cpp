/*
 * File:		main.cpp
 * Author:		Ryan Ringer
 * Purpose:		
 * Created on:	
 */

#include <iostream>
#include <stack>
#include <queue>
#include <list>
#include <string>


using namespace std;


int main(int argc, char** argv) {
	// Seed random number or initialize scanner


	// Constant Variables


	// Declare all Variables Here
	
	string word;		// the word
	bool isP = true;	// is palindrome
	stack<char> s;		// word backwards
	queue<char> q;		// word forwards
	

	// Input or initialize values Here
	cout << "Enter a word an I'll determine if it is a palindrome: " << endl;
	cin >> word;

	for (int i = 0; i < word.size(); i++) {
		s.push(tolower(word.at(i))); // placing the characters at the same spot
		q.push(tolower(word.at(i))); // while both ensured to be lowercase
	}

	// Process/Calculations Here

	while (!s.empty() && !q.empty()) {
		
		if (s.top() != q.front()) {
			isP = false;
		}

		s.pop();
		q.pop();

	}

	// Output Located Here

	if (isP) {
		cout << word << " is a palidrome" << endl;
	}
	else {
		cout << word << " is not a palindrome" << endl;
	}

	// Exit
	return 0;
}