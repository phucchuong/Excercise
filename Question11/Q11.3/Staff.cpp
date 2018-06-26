#include "Staff.h"

int Staff::countStaff = 0;

Staff::Staff()
{
	countStaff++;
}

Staff::Staff(int id, char * name, Date bdate, int dID, Date jdate, int level) :People(id, name, bdate)
{
	DepartmentID = dID;
	JoinedDate = jdate;
	Level = level;
	if (JoinedDate.Day > 31) JoinedDate.Day = 1;
	if (JoinedDate.Month > 12) JoinedDate.Month = 1;
	countStaff++;
}

Staff::Staff(const Staff & s) :People(s)
{
	DepartmentID = s.DepartmentID;
	JoinedDate = s.JoinedDate;
	Level = s.Level;
	countStaff++;
}


Staff::~Staff()
{
	countStaff--;
	cout << "\nDestructor of Staff class" ;
}

void Staff::PrintInfo()
{
	People::PrintInfo();
	cout << setw(6) << right << DepartmentID << setw(10)<< right; 
	JoinedDate.output();
	cout<< setw(6) << right << Level;
}

void Staff::SetDepartmentID(int id)
{
	DepartmentID = id;
}

void Staff::SetJoinedDate(int day, int month, int year)
{
	if (day <= 31) {
		JoinedDate.Day = day;
	}
	else {
		JoinedDate.Day = 1;
	}
	if (month <= 12) {
		JoinedDate.Month = month;
	}
	else {
		JoinedDate.Month = 1;
	}
	JoinedDate.Year = year;
}

void Staff::SetJoinedDate(Date date)
{
	JoinedDate.Day = date.Day;
	JoinedDate.Month = date.Month;
	JoinedDate.Year = date.Year;
}

void Staff::SetLevel(int level)
{
	Level = level;
}

int Staff::GetDepartmentID()
{
	return DepartmentID;
}

int Staff::GetLevel()
{
	return Level;
}

Date Staff::GetDate()
{
	return Birthday;
}

void Staff::input()
{
	People::input();
	cin.clear();
	rewind(stdin);
	cout << "Department ID: ";
	cin>> DepartmentID;
	cout << "Joined Day: ";
	unsigned char d, m;
	int y;
	cin >> d >> m >> y;
	this->SetJoinedDate(d, m, y);
	cin.clear();
	rewind(stdin);
	cout << "Level: ";
	cin >> Level;
}

int Staff::GetNumStaff()
{
	return countStaff;
}

type Staff::Getinstance()
{
	return type::staff;
}

void Staff::WtoF(ofstream & f)
{
	
	People::WtoF(f);
	f << " " << DepartmentID << " " << (int)JoinedDate.Day << " " << (int)JoinedDate.Month << " " << JoinedDate.Year << " " << Level ;
}

void Staff::RfromF(ifstream & f)
{
	People::RfromF(f);
	f >> DepartmentID >> JoinedDate.Day >> JoinedDate.Month >> JoinedDate.Year >> Level;
}


//int main() {
//	People *p;
//	p = new Staff;
//	p->input();
//	p->PrintInfo();
//}