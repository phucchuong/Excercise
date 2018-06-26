#pragma once
#include "People.h"
class Student :
	public People
{
private:
	int Grade;
	int NumofProject;
	float* Score = NULL;//score of each project.
	static int countStudent;
public:
	Student();
	Student(int id, char * name, Date date, int grade, int noproject, float *score = NULL);
	Student(const Student &s);
	~Student();
	void PrintInfo();
	void SetGrade(int grade);
	void SetNumofProject(int noProject);
	void SetScore(float *score);
	int GetGrade();
	int GetNumofProject();
	float* GetScore();
	float GetAvrScore();
	static int GetNumStudent();
	void input();
	type Getinstance();
	void WtoF(ofstream &f);
	void RfromF(ifstream &f);
	void modInfo();
private:
	float CalculateAvrScore();
};

