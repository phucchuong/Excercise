
#include"Node.h"
#include"People.h"
#include"Staff.h"
#include"Student.h"
#include"Teacher.h"

int main() {
	List a = NULL;

	ifstream file;
	file.open("ouput.txt",ios::in);
	if (file) {
		a = Node::ReadfromFile(file);
	}
	a->Show();

	a->SortbyType(a);
	cout << "*** after sort by group ***" << endl;
	a->Show();

	cout << "Students whose avrscore > 5" << endl;
	a->Avrthan5();

	ofstream fileout;
	fileout.open("Sorted.txt", ios::out);
	if (fileout) {
		a->WritetoFile(fileout);
	}
	/*Node* temp;
	Date b(2, 2, 1999);
	float sc[] = { 9 };

	temp = new Node;
	temp->Data = new Student(2, "Nguyen Van A", b, 12, 1, sc);
	a->Add(a, temp);
	cout << "people " << People::GetNumofPeople() << ": staff " << Staff::GetNumStaff()
		<< ": teacher " << Teacher::GetNumTeacher() << ": student" << Student::GetNumStudent() << endl;
	Date bd(1, 2, 1999),dj(6,6,2018);
	Date db(6, 6, 2018), jd(6, 6, 2018);
	temp = new Node;
	temp->Data = new Teacher(3, "Nguyen Thi F", bd, 1, jd, 12, 12, MATHS, ENGLISH);
	a->Add(a, temp);
	
	temp = new Node;
	temp->Data = new Staff(1, "Nguyen Phuc Chuong", bd, 12, dj, 11);
	a->Add(a, temp);

	cout << "people " << People::GetNumofPeople() << ": staff " << Staff::GetNumStaff()
		<< ": teacher " << Teacher::GetNumTeacher() << ": student" << Student::GetNumStudent() << endl;
	
	temp = new Node;
	temp->Data = new Student(2, "Nguyen Van B", b,12, 1,sc);
	a->Add(a, temp);

	temp = new Node;
	temp->Data = new Teacher(3, "Nguyen Thi H", bd, 1, jd, 12, 12, MATHS, ENGLISH);
	a->Add(a, temp);

	cout << "people " << People::GetNumofPeople() << ": staff " << Staff::GetNumStaff()
		<< ": teacher " << Teacher::GetNumTeacher() << ": student" << Student::GetNumStudent() << endl;
	

	temp = new Node;
	temp->Data = new Student(2, "Nguyen Van D", b, 12, 1, sc);
	a->Add(a, temp);

	temp = new Node;
	temp->Data = new Teacher(3, "Nguyen Thi C",bd,1,jd,12,12,MATHS,ENGLISH);
	a->Add(a, temp);

	temp = new Node;
	temp->Data = new Teacher(3, "Nguyen Thi G", bd, 1, jd, 12, 12, MATHS, ENGLISH);
	a->Add(a, temp);

	cout << "people " << People::GetNumofPeople() << ": staff " << Staff::GetNumStaff()
		<< ": teacher " << Teacher::GetNumTeacher() << ": student" << Student::GetNumStudent() << endl;
	a->Show();
	cout << "after sort by group" << endl;
	a->SortbyType(a);
	a->Show();
	ofstream file;
	file.open("ouput.txt",ios::out);
	if (file) {
		a->WritetoFile(file);
	}
	file.close();

	//cout << "Students whose avrscore's > 5" << endl;
	//a->Avrthan5();
	////List a1 = NULL;
	////cout << endl;
	////a1 = a->Clone();
	////Node::RemoveList(a);
	////a1->Show();
	////cout << "people " << People::GetNumofPeople() << ": staff " << Staff::GetNumStaff()
	////	<< ": teacher " << Teacher::GetNumTeacher() << ": student" << Student::GetNumStudent() << endl;
	////Node::RemoveList(a1);
	//cout << "people " << People::GetNumofPeople() << ": staff " << Staff::GetNumStaff()
	//	<< ": teacher " << Teacher::GetNumTeacher() << ": student" << Student::GetNumStudent() << endl;*/
	a->RemoveList(a);
	cout << "List after remove" << endl;
	a->Show();
	return 0;
}
