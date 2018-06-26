#include<iostream>
#include<iomanip>
using namespace std;

#pragma warning(disable: 4996)
struct _Student
{
	char *Name;
	int ID;
	float Score;
	_Student *pnext;

	_Student() {}
	_Student(const _Student &a);
	_Student* Input();
};

struct list {
	_Student *phead = NULL, *ptail = NULL;
}Student_list;

void Show();
void Add(_Student *p);
void Sort();
void Del(_Student *p);
void RemoveLess5();

int main() {

	while (1) {
		_Student *temp = new _Student;
		if (temp->Input() == NULL) break;
		else {
			Add(temp);
		}
	}
	Show();
	Sort();
	Show();
	RemoveLess5();
	Show();

	return 0;
}

_Student* _Student::Input()
{
	bool check;
	do {
		check = false;
		cout << "Nhap id: ";
		cin >> ID;
		if (ID == 0) return NULL;
		for (_Student *p = Student_list.phead; p; p = p->pnext) {
			if (p->ID == ID) {
				cout << "id sinh vien da ton tai" << endl;
				check = true;
				break;
			}
		}
	} while (check);
	cout << "Nhap ten: ";
	cin.clear();
	rewind(stdin);
	char name[60];
	gets_s(name, 30);
	Name = new char[strlen(name) + 1];
	strcpy_s(Name, strlen(name) + 1, name);
	do {
		cout << "Nhap diem: ";
		cin >> Score;
	} while (Score < 0 || Score>10);
	pnext = NULL;
	return this;
}

void Show()
{
	_Student *ds = Student_list.phead;
	cout << "*** Danh sach lop ***" << endl;
	while (ds) {
		cout << setw(6) << left << ds->ID << setw(30) << left << ds->Name << setw(4) << ds->Score << endl;
		ds = ds->pnext;
	}
}

_Student::_Student(const _Student &a)
{
	Name = new char[strlen(a.Name) + 1];
	strcpy_s(Name, strlen(a.Name)+1, a.Name);
	ID = a.ID;
	Score = a.Score;
	pnext = a.pnext;
}

void Add(_Student * p)
{
	if (Student_list.phead == NULL) {
		Student_list.phead = Student_list.ptail = p;
	}
	else {
		Student_list.ptail->pnext = p;
		Student_list.ptail = p;
	}
}
//#pragma warning(disable: 4996)
void Sort()
 {
	if (Student_list.phead) {
		if (Student_list.phead != Student_list.ptail) {
			_Student *p, *q;
			for (p = Student_list.phead; p->pnext; p = p->pnext) {
				_Student *t = p;
				for (q = p->pnext; q; q = q->pnext) {
					if (t->Score < q->Score) t = q;
				}
				// swap du lieu
				int id = t->ID;
				float score = t->Score;
				char name[50];
				strcpy_s(name,strlen(t->Name)+1, t->Name);

				t->ID = p->ID;
				t->Score = p->Score;
				delete t->Name;
				t->Name = new char[strlen(p->Name)+1];
				strcpy_s(t->Name, (strlen(p->Name) + 1), p->Name);

				p->ID = id;
				p->Score = score;
				delete p->Name;
				p->Name = new char[strlen(name) + 1];
				strcpy_s(p->Name, strlen(name) + 1, name);
			}
		}
	}
}

void Del(_Student * p)
{
	if (Student_list.phead) {
		if (Student_list.phead == p && Student_list.phead == Student_list.ptail) {
			_Student *temp = Student_list.phead;
			Student_list.phead = Student_list.ptail = NULL;
			delete temp;
		}
		else {
			if (Student_list.phead == p) {//xoa dau
				_Student *temp = p;
				p = p->pnext;
				Student_list.phead = p;
				delete temp;
			}
			else {
				if (Student_list.ptail == p) {
					_Student *q = Student_list.phead;
					while (q->pnext&&q->pnext != p) q = q->pnext;
					Student_list.ptail = q;
					Student_list.ptail->pnext = NULL;
					delete p;
				}
				else {
					_Student *q = Student_list.phead;
					while (q->pnext&&q->pnext != p) q = q->pnext;
					q->pnext = q->pnext->pnext;
					delete p;
				}
			}
		}
	}
}


void RemoveLess5()
{
	_Student *q = Student_list.phead;
	while (q) {
		if (q->Score < 5) {
			_Student *temp = q;
			q = q->pnext;
			Del(temp);
		}
		else {
			q = q->pnext;
		}
	}
}
