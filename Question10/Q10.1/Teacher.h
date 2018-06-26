#pragma once
#include"Staff.h"
#include"People.h"
enum Subject{MATHS,PHYS,ENGLISH};

class Teacher :
	public Staff
{
private:
	int Class;
	Subject Subject1, Subject2;
	static int countTeacher;
public:
	Teacher();
	~Teacher();
	Teacher(const Teacher &t);
	Teacher(int id, char *name, Date bdate, int dID, Date jdate, int level, int cl, Subject s1, Subject s2);
	void PrintInfo();
	void SetClass(int cl);
	void SetSubject1(Subject subject);
	void SetSubject2(Subject subject);
	int GetClass();
	Subject GetSubject1();
	Subject GetSubject2();
	void input();
	static int GetNumTeacher();
	type Getinstance();
	void WtoF(ofstream &f);
	void RfromF(ifstream &f);
};

