#include "Teacher.h"

int Teacher::countTeacher = 0;

Teacher::Teacher()
{
	countTeacher++;
}

Teacher::~Teacher()
{
	countTeacher--;
	cout << "\nDestructor of Teacher class" ;
}

Teacher::Teacher(const Teacher & t):Staff(t)
{
	Class = t.Class;
	Subject1 = t.Subject1;
	Subject2 = t.Subject2;
	countTeacher++;
}

Teacher::Teacher(int id, char * name, Date bdate, int dID, Date jdate, int level, int cl, Subject s1, Subject s2):Staff(id,name,bdate,dID,jdate,level)
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
	cout<< setw(8) << right;
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

////test
//int main() {
//	Date d(9, 5, 1997), d1(6, 6, 2018);
//	Teacher a(1,"chuong np",d,12,d1,1,12,MATHS,PHYS);
//	a.PrintInfo();
//	return 0;
//}