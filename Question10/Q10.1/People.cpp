#include "People.h"


int People::countPeople = 0;

People::People()
{
	countPeople++;
}

People::People(int id, char * name, Date date)
{
	ID = id;
	if (Name) delete[]Name;
	Name = new char[strlen(name) + 1];
	strcpy_s(Name, strlen(name) + 1, name);
	Birthday = date;
	if (Birthday.Day > 31) Birthday.Day = 1;
	if (Birthday.Month > 12)Birthday.Month = 1;
	countPeople++;
}


People::~People()
{
	delete[] Name;
	Name = NULL;
	countPeople--;
	cout << "Destructor of People" << endl;
}

People::People(const People & p)
{
	this->ID = p.ID;
	if (Name) {
		delete this->Name;
		Name = NULL;
	}
	if(!Name) this->Name = new char[strlen(p.Name) + 1];
	strcpy_s(this->Name, strlen(p.Name) + 1, p.Name);
	this->Birthday = p.Birthday;
	countPeople++;
}

void People::PrintInfo()
{
	cout << setw(6) << left << ID << setw(30) << left << Name << setw(10) << right;
	Birthday.output();
}

void People::SetName(char * s)
{
	if (Name) delete[]Name;
	Name = new char[strlen(s) + 1];
	strcpy_s(Name, strlen(s) + 1, s);
}

void People::SetBirthday(int day, int month, int year)
{
	if (day <= 31) {
		Birthday.Day = day;
	}
	else {
		Birthday.Day = 1;
	}
	if (month <= 12) {
		Birthday.Month = month;
	}
	else {
		Birthday.Month = 1;
	}
	Birthday.Year = year;
}

void People::SetBirthday(Date date)
{
	Birthday.Day = date.Day;
	Birthday.Month = date.Month;
	Birthday.Year = date.Year;
}

void People::SetID(int id)
{
	ID = id;
}

int People::GetID()
{
	return ID;
}

char * People::GetName()
{
	return Name;
}

Date People::GetDate()
{
	return Birthday;
}

int People::GetNumofPeople()
{
	return countPeople;
}

void People::input()
{
	cout << "ID: ";
	cin >> ID;
	cout << "Name: ";
	cin.clear();
	rewind(stdin);
	char name[30];
	gets_s(name, 30);
	if (Name != NULL) {
		delete[]Name;
		Name = NULL;
	}
	Name = new char[strlen(name) + 1];
	strcpy_s(Name, strlen(name) + 1, name);
	cout << "Birthday: ";
	unsigned char d, m;
	int y;
	cin >> d >> m >> y;
	this->SetBirthday(d, m, y);
}

type People::Getinstance()
{
	return type::people;
}

void People::WtoF(ofstream & f)
{
	f << ID << " " << Name << "," << (int)Birthday.Day << " " << (int)Birthday.Month << " " << Birthday.Year ;
}

void People::RfromF(ifstream & f)
{
	f >> ID;
	string s;
	getline(f, s,',');
	if (Name) {
		delete[] Name;
		Name = NULL;
	}
	Name = new char[s.length() + 1];
	strcpy_s(Name, s.length() + 1,s.c_str());
	f >> Birthday.Day >> Birthday.Month >> Birthday.Year;
}


////test
//int main() {
//	cout << "so people: " << People::GetNumofPeople() << endl;
//	People a;
//	a.SetID(1);
//	a.SetName("nguyen phuc chuong");
//	a.SetBirthday(9, 5, 1997);
//	a.PrintInfo();
//	cout << "\nso people: " << People::GetNumofPeople() << endl;
//	People b = a;
//	cout << "so people: " << People::GetNumofPeople() << endl;
//	cout << endl;
//	b.PrintInfo();
//	a.~People();
//	cout << endl;
//	b.PrintInfo();
//	cout << "\nso people: " << People::GetNumofPeople();
//}

Date::Date(int day, int month, int year)
{

	if (day <= 31) {
		Day = day;
	}
	else {
		Day = 1;
	}
	if (month <= 12) {
		Month = month;
	}
	else {
		Month = 1;
	}
	Year = year;
}
