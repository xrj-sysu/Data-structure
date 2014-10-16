// queue is a container adapter based on deque in STL source code
// just simple to achieve

#include<iostream>
#include<deque>
using namespace std;

template<class T>
class myQueue {
	public:
		bool empty() const {
		    return c.empty(); 
		}
		int size() const {
		    return c.size();
		}
		T& front() {
			return c.front();
		}
		T& back() {
			return c.back();
		}
		void push(const T& x) {
			c.push_back(x);
		}
		void pop() {
			c.pop_front();
		}
	private:
		deque<T> c;
};
