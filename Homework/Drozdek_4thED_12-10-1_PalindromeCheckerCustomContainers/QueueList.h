#pragma once

#include "Node.h"

using namespace std;
class QueueList {

private:
	Node* front;
	Node* tail;
public:

	QueueList();
	~QueueList();
	void push(char);
	void pop();
	char viewFront();
	bool isEmpty();
};