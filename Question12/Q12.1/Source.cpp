#include"People.h"
#include"Staff.h"
#include"Student.h"
#include"Teacher.h"
#include<list>
#include<Windows.h>
/*#include "vld.h"
#pragma comment(lib, "vld.lib")*/


void Add(People* people, list<People*> &l);
void Add(Staff* staff, list<People*> &l);
void Add(Student* student, list<People*> &l);
void Add(Teacher* teacher, list<People*> &l);
void Show(list<People*> l);
void ModInfo(list<People*> l);
void remove(list<People*> &l);


int main() {
	list<People*> list;
	Date d(1, 2, 1999);
	People *people=new People(1, "dwdfew", d);
	Add(people, list);
	People *people2 = new People(2, "dwdfew", d);
	Add(people2, list);
	Staff *staff=new Staff(5, "dsadfwq", d, 12, d, 23);
	Add(staff, list);
	Staff *staff1 = new Staff(3, "dngue", d, 12, d, 23);
	Add(staff1, list);
	Staff *staff2 = new Staff(4, "gnuyen", d, 12, d, 23);
	Add(staff2, list);
	Teacher *teacher=new Teacher(6, "nguyen", d, 23, d, 11, 12, MATHS, ENGLISH);
	Add(teacher, list);
	float score[] = { 8,7,9 };
	Student *student=new Student(9, "chuogn", d, 12, 3, score);
	Add(student, list);


	Show(list);
	bool cont = false; // skip modify
	while (cont) {
		ModInfo(list);
		Show(list);
		cout << "continue modifier (y/n)? ";
		cin.clear();
		rewind(stdin);
		if (getchar() == 'n') cont = false;
	}
	//Sleep(5000);
	remove(list);
	//Sleep(5000);
	return 0;
}

void Add(People* people, list<People*> &l)
{
	l.push_back(people);
}

void Add(Staff * staff, list<People*>& l)
{
	l.push_back(dynamic_cast<People*>(staff));
}

void Add(Student * student, list<People*>& l)
{
	l.push_back(dynamic_cast<Student*>(student));
}

void Add(Teacher * teacher, list<People*>& l)
{
	l.push_back(dynamic_cast<Teacher*>(teacher));
}

void Show(list<People*> l)
{
	list<People*>::iterator i;
	for (i = l.begin(); i != l.end(); i++) {
		People* temp = *i;
		temp->PrintInfo();
		cout << endl;
	}
}

void ModInfo(list<People*> l)
{
	cout << "input ID: ";
	int id;
	cin >> id;
	list<People*>::iterator i;
	People *temp = NULL;
	for (i = l.begin(); i != l.end(); i++) {
		temp = *i;
		if(temp->GetID() == id) {
			temp->modInfo();
			break;
		}
	}
}

void remove(list<People*> &l) {
	list<People*>::iterator i;
	People *temp;
	for (i = l.begin(); i != l.end(); i++) {
		temp = *i;
		delete temp;
	}
	l.clear();
}
