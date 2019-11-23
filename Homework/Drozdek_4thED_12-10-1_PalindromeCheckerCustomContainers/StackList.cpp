
#include "StackList.h"

using namespace std;

StackList::StackList() {
	this->top = nullptr; 
}
StackList::~StackList() {
	Node* temp;
	while (top != nullptr) {
		temp = this->top->ptr;
		delete this->top;
		this->top = temp;
	}

}
void StackList::push(char c) {
	Node* n = new Node;
	n->data = c;
	n->ptr = this->top;
	this->top = n;
}
void StackList::pop() {
	Node* n = new Node;
	n = this->top;
	this->top = this->top->ptr;
	delete n;
}
char StackList::viewTop() {
	return this->top->data;
}
bool StackList::isEmpty() {
	bool empty = false;

	if (this->top == nullptr) {
		empty = true;
	}
	return empty;
}