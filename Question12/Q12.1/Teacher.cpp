#include "Teacher.h"

int Teacher::countTeacher = 0;

Teacher::Teacher()
{
	countTeacher++;
}

Teacher::~Teacher()
{
	countTeacher--;
	cout << "Destructor of Teacher" << endl;
}

Teacher::Teacher(const Teacher & t) :Staff(t)
{
	Class = t.Class;
	Subject1 = t.Subject1;
	Subject2 = t.Subject2;
	countTeacher++;
}

Teacher::Teacher(int id, char * name, Date bdate, int dID, Date jdate, int level, int cl, Subject s1, Subject s2) :Staff(id, name, bdate, dID, jdate, level)
{
	Class = cl;
	Subject1 = s1;
	Subject2 = s2;
	countTeacher++;
}

void Teacher::PrintInfo()
{
	Staff::PrintInfo();
	cout << setw(6) << right << Class << setw(8) << right;
	switch (Subject1)
	{
	case MATHS:
		cout << "Maths";
		break;
	case PHYS:
		cout << "Phys";
		break;
	case ENGLISH:
		cout << "English";
		break;
	default:
		cout << "Unknow";
		break;
	};
	cout << setw(8) << right;
	switch (Subject2)
	{
	case MATHS:
		cout << "Maths";
		break;
	case PHYS:
		cout << "Phys";
		break;
	case ENGLISH:
		cout << "English";
		break;
	default:
		cout << "Unknow";
		break;
	};
}

void Teacher::SetClass(int cl)
{
	Class = cl;
}

void Teacher::SetSubject1(Subject subject)
{
	Subject1 = subject;
}

void Teacher::SetSubject2(Subject subject)
{
	Subject2 = subject;
}

int Teacher::GetClass()
{
	return Class;
}

Subject Teacher::GetSubject1()
{
	return Subject1;
}

Subject Teacher::GetSubject2()
{
	return Subject2;
}

void Teacher::input()
{
	People::input();
	cout << "Class: ";
	cin >> Class;
	int choice;
	do {
		cout << "Subject:" << "0.Maths 1.Phys 2.English : ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			Subject1 = MATHS;
			break;
		case 1:
			Subject1 = PHYS;
			break;
		case 2:
			Subject1 = ENGLISH;
			break;
		default:
			cout << "dont have this choice!" << endl;
			break;
		}
	} while (choice < 0 || choice>2);

	do {
		cout << "Second Subject:" << "0.Maths 1.Phys 2.English : ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			Subject2 = MATHS;
			break;
		case 1:
			Subject2 = PHYS;
			break;
		case 2:
			Subject2 = ENGLISH;
			break;
		default:
			cout << "dont have this choice!" << endl;
			break;
		}
	} while (choice < 0 || choice>3);
}

int Teacher::GetNumTeacher()
{
	return countTeacher;
}

type Teacher::Getinstance()
{
	return type::teacher;
}

void Teacher::WtoF(ofstream & f)
{

	Staff::WtoF(f);
	f << " " << Class << " ";
	switch (Subject1)
	{
	case MATHS:
		f << "MATHS";
		break;
	case 2:
		f << "PHYS";
		break;
	case 3:
		f << "ENGLISH";
		break;
	}
	f << ",";
	switch (Subject2)
	{
	case MATHS:
		f << "MATHS";
		break;
	case 2:
		f << "PHYS";
		break;
	case 3:
		f << "ENGLISH";
		break;
	}
}

void Teacher::RfromF(ifstream & f)
{
	Staff::RfromF(f);
	f >> Class;
	string s;
	f.get();
	getline(f, s, ',');
	if (s == "MATHS") {
		Subject1 = MATHS;
	}
	else {
		if (s == "PHYS") {
			Subject1 = PHYS;
		}
		else {
			Subject1 = ENGLISH;
		}
	}

	getline(f, s);
	if (s == "MATHS") {
		Subject2 = MATHS;
	}
	else {
		if (s == "PHYS") {
			Subject2 = PHYS;
		}
		else {
			Subject2 = ENGLISH;
		}
	}
}

void Teacher::modInfo()
{
	cout << "field need to modify: " << endl
		<< "1.ID 2.Name 3.Birthday 4.Departement ID 5.joined Day 6.Level 7.Class 8.Subject1 9.Subject2" << endl;
	int choice;
	int s;
	cin >> choice;
	Date a;
	switch (choice) {
	case 1:
		cout << "ID: ";
		int id;
		cin >> id;
		SetID(id);
		break;
	case 2:
		cout << "Name: ";
		cin.clear();
		rewind(stdin);
		char name[50];
		gets_s(name,50);
		SetName(name);
		break;
	case 3:
		cout << "day: ";
		cin >> a.Day;
		cout << "month: ";
		cin >> a.Month;
		cout << "year: ";
		cin >> a.Year;
		SetBirthday(a);
		break;
	case 4:
		cout << "Departement ID: ";
		int department;
		cin >> department;
		SetDepartmentID(department);
		break;
	case 5:
		cout << "day: ";
		cin >> a.Day;
		cout << "month: ";
		cin >> a.Month;
		cout << "year: ";
		cin >> a.Year;
		SetJoinedDate(a);
		break;
	case 6:
		cout << "Level: ";
		int level;
		cin >> level;
		SetLevel(level);
		break;
	case 7:
		cout << "class: ";
		int cl;
		cin >> cl;
		SetClass(cl);
		break;
	case 8:

		do {
			cout << "0.Math 1.Phys 2.English" << endl;
			cin >> s;
		} while (s < 0 || s>2);
		switch (s) {
		case 0:
			SetSubject1(MATHS);
			break;
		case 1:
			SetSubject1(PHYS);
			break;
		case 2:
			SetSubject1(ENGLISH);
			break;
		}
		break;
	case 9:
		do {
			cout << "0.Math 1.Phys 2.English" << endl;
			cin >> s;
		} while (s < 0 || s>2);
		switch (s) {
		case 0:
			SetSubject1(MATHS);
			break;
		case 1:
			SetSubject1(PHYS);
			break;
		case 2:
			SetSubject1(ENGLISH);
			break;
		}
		break;
	default:
		cout << "don't have this choice!" << endl;
	}
}

////test
//int main() {
//	Date d(9, 5, 1997), d1(6, 6, 2018);
//	Teacher a(1,"chuong np",d,12,d1,1,12,MATHS,PHYS);
//	a.PrintInfo();
//	return 0;
//}