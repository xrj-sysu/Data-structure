#include<iostream>
using namespace std;

const int maxStack = 100;

template <class T>
class Stack {
    public:
        Stack();
        bool empty() const;
        void pop();
        T& top();
        void push(const T &item);
        int size() const;
    private:
        int length;
        T entry[maxStack];
};
template <class T>
Stack<T>::Stack() {
	length = 0;
}
template <class T>
bool Stack<T>::empty() const {
    return length == 0;
}
template <class T>
void Stack<T>::pop() {
	if (length == 0) {
		return;
	}
	length--;
}
template <class T>
T& Stack<T>::top() {
    if (length > 0) {
        return entry[length-1];
    }
}
template <class T>
void Stack<T>::push(const T &item) {
	if (length >= maxStack) {
		return;
	}
	entry[length] = item;
	length++;
}
template <class T>
int Stack<T>::size() const {
    return length;
}
