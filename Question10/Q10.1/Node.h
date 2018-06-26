#include"People.h"
#include"Staff.h"
#include"Student.h"
#include"Teacher.h"
#pragma once
class Node;
typedef Node* List;
class Node
{
public:
	People *Data=NULL;
	Node *pnext = NULL;
	Node();
	~Node();
	Node(People *p);
	Node(const Node &a);
	
	static void Input(List &L);
	void Show();
	void Add(List &L, Node* p);
	void Avrthan5();
	void SortbyType(List &L);
	List Clone();
	List Remove(Node* p);
	void RemoveList(List& p);
	void WritetoFile(ofstream &f);
	static List ReadfromFile(ifstream &f);
};

