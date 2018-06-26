#include"People.h"
#include"Staff.h"
#include"Student.h"
#include"Teacher.h"
#include"Node.h"
#include"Node.cpp"
#include<Windows.h>

int main() {
	Node<People> *List = NULL;
	Date d(9, 5, 1997);
	People *a = new People(1, "chuong", d);
	Node<People> *p = new Node<People>(a);
	List = List->addNode(p);
	Node<People> *test = p;
	a = new People(2, "chuong", d);
	p = new Node<People>(a);
	List = List->addNode(p);
	a = new People(3, "chuong", d);
	p = new Node<People>(a);
	List = List->addNode(p);
	
	a = new Staff(4, "afiqwui", d, 12, d, 12);
	p = new Node<People>(a);	
	List = List->addNode(p);
	a = new Staff(5, "afiqwui", d, 12, d, 12);
	p = new Node<People>(a);
	List = List->addNode(p);
	a = new Staff(6, "afiqwui", d, 12, d, 12);
	p = new Node<People>(a);
	List = List->addNode(p);


	//print information
	Node<People> *t = List;
	t = List;
	while (t) {
		t->data->PrintInfo();
		cout << endl;
		t = t->next;
	}

	List=List->removeNode(test);

	t = List;
	while (t) {
		t->data->PrintInfo();
		cout << endl;
		t = t->next;
	}
	Sleep(5000);
	List->removeAllNode(List);
	Sleep(5000);
	return 0;
}