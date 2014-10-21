#include<iostream>
using namespace std;

enum ErrorCode {
	success,
	underflow,
	overflow
};

template<class QueueEntry>
struct Node {
	QueueEntry data;
	Node<QueueEntry>* next;
};

template<class QueueEntry>
class MyQueue {
	public:
		MyQueue();
		bool empty() const;
		ErrorCode append(const QueueEntry& item);
		ErrorCode serve();
		ErrorCode retrieve(QueueEntry& item) const;
		int size() const;
		void clear();
		ErrorCode retrieve_and_serve(QueueEntry& item);
	private:
		Node<QueueEntry>* front;
		Node<QueueEntry>* rear;
};

template<class QueueEntry>
MyQueue<QueueEntry>::MyQueue() {
	front = rear = NULL;
}
template<class QueueEntry>
bool MyQueue<QueueEntry>::empty() const {
    int count = 0;
    Node<QueueEntry>* p = front;
    while (p != NULL) {
    	count++;
    	p = p->next;
    }
    return count == 0;
}
template<class QueueEntry>
ErrorCode MyQueue<QueueEntry>::append(const QueueEntry& item) {
	Node<QueueEntry>* p = new Node<QueueEntry>();
	if (p == NULL) {
		return overflow;
	}
	p->data = item;
	p->next = NULL;
	if (rear == NULL) {
		front = rear = p;
	} else {
	      rear->next = p;
		  rear = rear->next;	
	  }
	return success;
}
template<class QueueEntry>
ErrorCode MyQueue<QueueEntry>::serve() {
	if (front == NULL) {
		return underflow;
	}
	Node<QueueEntry>* p = front;
	front = front->next;
	if (front == NULL) {
		rear = NULL;
	}
	delete p;
	return success;
}
template<class QueueEntry>
ErrorCode MyQueue<QueueEntry>::retrieve(QueueEntry& item) const {
    if (front == NULL) {
    	return underflow;
    }
    item = front->data;
    return success;
}
template<class QueueEntry>
int MyQueue<QueueEntry>::size() const {
    int count = 0;
    Node<QueueEntry>* p = front;
    while (p != NULL) {
    	count++;
    	p = p->next;
    }
    return count;
} 
template<class QueueEntry>
void MyQueue<QueueEntry>::clear() {
	while (!empty()) {
		serve();
	}
}
template<class QueueEntry>
ErrorCode MyQueue<QueueEntry>::retrieve_and_serve(QueueEntry& item) {
	if (front == NULL) {
		return underflow;
	}
	item = front->data;
	Node<QueueEntry>* p = front;
	front = front->next;
	if (front == NULL) {
		rear = NULL;
	}
	delete p;
	return success;
}

