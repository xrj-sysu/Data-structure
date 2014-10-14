#include<iostream>
using namespace std;

enum ErrorCode {
    success,
    underflow,
    overflow
};

const int maxQueue = 100;

template<class QueueEntry>
class MyQueue {
    public:
        MyQueue();
        bool empty() const;
        ErrorCode append(const QueueEntry &item);
        ErrorCode serve();
        ErrorCode retrieve(QueueEntry &item) const;
        bool full() const;
        int size() const;
        void clear();
        ErrorCode retrieve_and_serve(QueueEntry &item);
    private:
        int count;
		int front;                             
        int rear;                              
        QueueEntry entry[100];       
};
template<class QueueEntry>
MyQueue<QueueEntry>::MyQueue() {
	count = 0;
	front = 0;
	rear = maxQueue - 1;
}
template<class QueueEntry>
int MyQueue<QueueEntry>::size() const {
	return count;
}
template<class QueueEntry>
bool MyQueue<QueueEntry>::empty() const {
    return count == 0;
}
template<class QueueEntry>
ErrorCode MyQueue<QueueEntry>::append(const QueueEntry &item) {
	if (count >= maxQueue) {
		return overflow;
	}
	count++;
	rear = ((rear + 1) == maxQueue) ? 0 : (rear + 1);
	entry[rear] = item;
	return success;
}
template<class QueueEntry>
ErrorCode MyQueue<QueueEntry>::serve() {
	if (count <= 0) {
		return underflow;
	}
	count--;
	front = ((front + 1) == maxQueue) ? 0 : (front + 1);
	return success;
}
template<class QueueEntry>
ErrorCode MyQueue<QueueEntry>::retrieve(QueueEntry &item) const {
    if (count <= 0) {
    	return underflow;
    }
    item = entry[front];
    return success;
}
template<class QueueEntry>
bool MyQueue<QueueEntry>::full() const {
    return count == maxQueue;
}
template<class QueueEntry>
void MyQueue<QueueEntry>::clear() {
	count = 0;
	front = 0;
	rear = maxQueue - 1;
}
template<class QueueEntry>
ErrorCode MyQueue<QueueEntry>::retrieve_and_serve(QueueEntry &item) {
    ErrorCode err;
    err = retrieve(item);
    if (err != success) {
        return err;
    }
    err = serve();
    return err;
}
