#include "Stack.h"



template<class T>Stack<T>::Stack(int n)
{
	stack = new T[n];
	total = 0;
	size = n;
}


template<class T>Stack<T>::~Stack()
{
	delete[] stack;
	stack = NULL;
	total = 0;
}

template<class T>
bool Stack<T>::push(T obj)
{
	if (isFull() == false) {
		stack[total] = obj;
		total++;
		return true;// to indicate success
	}
	else {
		return false; //to indicate failure
	}
}

template<class T>
T Stack<T>::pop()
{
	if (isEmpty() == false) {
		T object = stack[total - 1];
		stack[total - 1] = NULL;
		total--;
		return object;
	}
	else {
		return NULL;
	}
}

template<class T>
bool Stack<T>::isEmpty()
{
	if (total == 0) {
		return true;
	}
	else {
		return false;
	}
}

template<class T>
bool Stack<T>::isFull()
{
	if (total == size) {
		return true;
	}
	else {
		return false;
	}
}

template<class T>
T Stack<T>::getItem(int i)
{
	return stack[i - 1];
}

template<class T>
int Stack<T>::getTotal()
{
	return total;
}
