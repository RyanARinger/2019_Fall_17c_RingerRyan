#pragma
#include "Node.h"

using namespace std;

class StackList {

private:
	Node* top;

public:
	
	StackList();
	~StackList();
	void push(char);
	void pop();
	char viewTop();
	bool isEmpty();

};
