#pragma once
#include"People.h"

template<class T>
class Node
{
public:
	T *data;
	Node<T>* next=NULL; 
	Node();
	Node(People *p);
	~Node();
	Node<T>* addNode(Node<T> *p);
	Node<T>* removeNode(Node<T> *p);
	void removeAllNode(Node<T>*& List);
};

