#include<iostream>
using namespace std;
enum ErrorCode {
	success,
	underflow,
	overflow
};

template<class StackEntry>
struct Node {
	StackEntry data;
	Node* next;
};

template<class StackEntry>
class MyStack {
	public:
		MyStack();
	    bool empty() const;
	    int size() const;
	    ErrorCode pop();
	    ErrorCode top(StackEntry& item) const;
	    ErrorCode push(const StackEntry& item);
	    void clear();
	private:
		Node<StackEntry>* pTop;
};

template<class StackEntry>
MyStack<StackEntry>::MyStack() {
	pTop = NULL;
}
template<class StackEntry>
bool MyStack<StackEntry>::empty() const {
    int count = 0;
    Node<StackEntry>* p = pTop;
	while (p != NULL) {
		count++;
		p = p->next;
	}
	return count == 0;
}
template<class StackEntry>
int MyStack<StackEntry>::size() const {
	int count = 0;
	Node<StackEntry>* p = pTop;
	while (p != NULL) {
		count++;
		p = p->next;
	}
	return count;
}
template<class StackEntry>
ErrorCode MyStack<StackEntry>::pop() {
	Node<StackEntry>* p = pTop;
	if (pTop == NULL) {
		return underflow;
	}
	pTop = pTop->next;
	delete p;
	return success;	
}
template<class StackEntry>
ErrorCode MyStack<StackEntry>::top(StackEntry& item) const {
    if (pTop == NULL) {
    	return underflow;
    }
    item = pTop->data;
	return success;	
}
template<class StackEntry>
ErrorCode MyStack<StackEntry>::push(const StackEntry &item) {
	Node<StackEntry>* p = new Node<StackEntry>();
	p->data = item;
	p->next = pTop;
	if (p == NULL) {
		return overflow;
	}
	pTop = p;
	return success;
}
template<class StackEntry>
void MyStack<StackEntry>::clear() {
	while(!empty()) {
		pop();
	}
}
