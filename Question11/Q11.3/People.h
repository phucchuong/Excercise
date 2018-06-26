#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
using namespace std;

enum type { people, staff, teacher, student };

struct Date {
	int Year, Day, Month;;
	Date() {}
	Date(int day, int month, int year);
	void output() {
		cout << (Day < 10 ? "0" : "") << Day << "/" << (Month < 10 ? "0" : "") << Month << "/" << Year;
	}
};

#pragma once
class People
{
protected:
	char *Name = NULL;
	Date Birthday;
	int ID;
	static int countPeople;
public:
	People();
	People(int id, char* name, Date date);
	virtual ~People();
	People(const People &p);
	virtual void PrintInfo();
	void SetName(char *s);
	void SetBirthday(int day, int month,int year);
	void SetBirthday(Date date);
	void SetID(int id);
	int GetID();
	char* GetName();
	Date GetDate();
	static int GetNumofPeople();
	virtual void input();
	virtual type Getinstance();
	virtual void WtoF(ofstream &f);
	virtual void RfromF(ifstream &f);
};

