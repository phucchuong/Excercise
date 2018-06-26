#pragma once
#include "People.h"


class Staff :
	public People
{
protected:
	int DepartmentID;
	Date JoinedDate;
	int Level;
	static int countStaff;
public:
	Staff();
	Staff(int id, char *name, Date bdate, int dID, Date jdate, int level);
	Staff(const Staff &s);
	virtual ~Staff();
	virtual void PrintInfo();
	void SetDepartmentID(int id);
	void SetJoinedDate(int day, int month,int year);
	void SetJoinedDate(Date date);
	void SetLevel(int level);
	int GetDepartmentID();
	int GetLevel();
	Date GetDate();
	void input();
	static int GetNumStaff();
	type Getinstance();
	void WtoF(ofstream &f);
	void RfromF(ifstream &f);
};

