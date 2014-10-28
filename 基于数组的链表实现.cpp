#include<iostream>
using namespace std;

const int max_list = 100;

enum Error_code {
	success,
	overflow,
	error_access
};

template<class T>
class List {
	public:
		List();
		int size() const;
		bool full() const;
		bool empty() const;
		void clear();
		void traverse(void (*visit)(T& item));
		Error_code retrieve(int position, T& item) const;
		Error_code replace(int position, const T& item);
		Error_code remove(int position, T& item);
		Error_code insert(int position, const T& item);
	protected:
		int count;
		T entry[max_list];
};

template<class T>
List<T>::List() {
	count = 0;
}
template<class T>
int List<T>::size() const {
    return count;
}
template<class T>
bool List<T>::full() const {
    return count >= max_list;
}
template<class T>
bool List<T>::empty() const {
    return count == 0;
}
template<class T>
void List<T>::clear() {
	count = 0;
}
template<class T>
void List<T>::traverse(void (*visit)(T& item)) {
	for (int i = 0; i < count; ++i) {
		visit(entry[i]);
	}
}
template<class T>
Error_code List<T>::retrieve(int position, T& item) const {
    if (position < 0 || position >= count) {
    	return error_access;
    }
    item = entry[position];
    return success;
}
template<class T>
Error_code List<T>::replace(int position, const T& item) {
	if (position < 0 || position >= count) {
		return error_access;
	}
	entry[position] = item;
	return success;
}
template<class T>
Error_code List<T>::remove(int position, T& item) {
	if (position < 0 || position >= count) {
		return error_access;
	}
	item = entry[position];
	for (int i = position; i < count-1; ++i) {
		entry[i] = entry[i+1];
	}
	count--;
	return success;
}
template<class T>
Error_code List<T>::insert(int position, const T& item) {
	if (full()) {
		return overflow;
	}
	if (position < 0 || position > count) {
		return error_access;
	}
	for (int i = count; i > position; --i) {
		entry[i] = entry[i-1];
	}
	entry[position] = item;
	count++;
	return success;
}
