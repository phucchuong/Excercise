#include "Node.h"


template<class T>Node<T>::Node()
{
}


template<class T>Node<T>::~Node()
{

}

template<class T>Node<T>::Node(People * p)
{
	data = p;
}


template<class T>Node<T>* Node<T>::addNode(Node<T>* p)
{
	Node<T>* temp = this;
	if (temp == NULL) {
		temp = p;
		return temp;
	}
	else {
		while (temp->next) {
			temp = temp->next;
		}
		temp->next = p;
		return this;
	}
}

template<class T>
Node<T>* Node<T>::removeNode(Node<T> *p)
{
	Node<T> *temp = this;
	if (p == temp) {//p la nut dau
		temp = temp->next;
		delete p->data;
		//p->next = NULL;
		return temp;
	}
	else {
		while (temp->next&&temp->next != p) {
			temp = temp->next;
		}
		temp->next = temp->next->next;
		delete p->data;
		p->next = NULL;
		p = NULL;
		return this;
	}
}

template<class T>
void Node<T>::removeAllNode(Node<T>*& list)
{
	while (list) {
		list = list->removeNode(list);
	}
}



