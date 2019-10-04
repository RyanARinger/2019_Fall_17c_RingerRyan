#include <iostream>

#include "QueueList.h"

using namespace std;

QueueList::QueueList() {
	this->front = new Node;
	this->tail = this->front;
	this->front->data = '/n';
	this->tail->ptr = nullptr;
}

QueueList::~QueueList() {
	Node* n;
	while (this->front != nullptr) {
		n = this->front->ptr;
		delete this->front;
		this->front = n;
	}
}

void QueueList::push(char c) {
	
	/*Node* n = new Node;
	n->data = c;
	cout << n->data;

	this->tail->ptr = n;
	this->tail = n;
	cout << tail->data << endl;*/
	
	
	Node* n = new Node;
	this->tail->data = c;
	this->tail->ptr = n;
	this->tail = n;
	this->tail->ptr = nullptr;

}

void QueueList::pop() {
	Node* n = new Node;
	n = this->front->ptr;
	delete this->front;
	this->front = n;
}

char QueueList::viewFront() {
	return this->front->data;
}

bool QueueList::isEmpty(){
	bool empty = false;
	   	  
	if (this->front->data == '\n' || this->front == nullptr) {
		empty = true;
	}
	return empty;
}