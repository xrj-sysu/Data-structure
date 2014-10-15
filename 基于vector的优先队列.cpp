#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

/*
   以下的make_heap(), push_heap(), pop_heap()都是泛型算法 
*/
template<class T>
class my_priority_queue {
	public:
	    my_priority_queue() : vec() {}
	    template<class InputIterator>
	    my_priority_queue(InputIterator first, InputIterator last) : vec(first, last) {
	    	make_heap(vec.begin(), vec.end());
	    }
	    bool empty() const {
		    return vec.size() == 0;
		}
		int size() const {
		    return vec.size();
		}
		T& top() {
		    return vec[0];
		}
		void push(const T& x) {
		    vec.push_back(x);
		    push_heap(vec.begin(), vec.end());
        }
		void pop() {
			// heap本身没有实质pop掉元素 
			pop_heap(vec.begin(), vec.end());
			vec.pop_back();
		}
	private:
		vector<T> vec;
};
