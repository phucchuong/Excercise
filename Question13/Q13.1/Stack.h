#include<iostream>
using namespace std;

#pragma once
// T is type of object which was store in stack
template<class T>class Stack
{
private:
	T *stack;
	int total,size;
public:
	Stack(int n);
	~Stack();
	bool push(T obj);
	T pop();
	bool isEmpty();
	bool isFull();
	T getItem(int i);
	int getTotal();
};

