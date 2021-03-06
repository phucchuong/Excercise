#include "Student.h"

int Student::countStudent = 0;

Student::Student()
{
	countStudent++;
}

Student::Student(int id, char * name, Date date, int grade, int noproject, float * score) :People(id, name, date)
{
	Grade = grade;
	NumofProject = noproject;
	if (score) {
		Score = new float[NumofProject];
		memcpy(Score, score, NumofProject * sizeof(float));
	}
	countStudent++;
}

Student::Student(const Student & s) :People(s)
{
	this->Grade = s.Grade;
	this->NumofProject = s.NumofProject;
	delete[] this->Score;
	this->Score = new float[s.NumofProject];
	memcpy(this->Score, s.Score, s.NumofProject * sizeof(float));
	countStudent++;
}

Student::~Student()
{
	delete[] Score;
	Score = NULL;
	countStudent--;
	cout << "Destructor of Student" << endl;
}

void Student::PrintInfo()
{
	People::PrintInfo();
	cout << setw(6) << right << Grade << setw(6) << right << NumofProject << setw(6) << right;
	if (Score) {
		for (int i = 0; i < NumofProject; i++) {
			cout << Score[i] << " ";
		}
	}
}

void Student::SetGrade(int grade)
{
	Grade = grade;
}

void Student::SetNumofProject(int noProject)
{
	NumofProject = noProject;
}

void Student::SetScore(float * score)
{
	if (Score) {
		delete[] Score;
	}
	Score = new float[NumofProject];
	memcpy(Score, score, NumofProject * sizeof(float));
}

int Student::GetGrade()
{
	return Grade;
}

int Student::GetNumofProject()
{
	return NumofProject;
}

float * Student::GetScore()
{
	return Score;
}

float Student::GetAvrScore()
{
	return this->CalculateAvrScore();
}

int Student::GetNumStudent()
{
	return countStudent;
}

void Student::input()
{
	People::input();
	cout << "Grade: ";
	cin >> Grade;
	cout << "Number of project : ";
	cin >> NumofProject;
	if (!Score) {
		delete[]Score;
	}
	Score = new float[NumofProject];
	for (int i = 0; i < NumofProject; i++) {
		cout << "Score of Project " << i + 1 << ": ";
		cin >> Score[i];
	}
}

type Student::Getinstance()
{
	return type::student;
}

void Student::WtoF(ofstream & f)
{

	People::WtoF(f);
	f << " " << Grade << " " << NumofProject << " ";
	for (int i = 0; i < NumofProject; i++) {
		f << Score[i] << " ";
	}
}

void Student::RfromF(ifstream & f)
{
	People::RfromF(f);
	f >> Grade >> NumofProject;
	if (Score) {
		delete[]Score;
		Score = NULL;
	}
	Score = new float[NumofProject];
	for (int i = 0; i < NumofProject; i++) {
		f >> Score[i];
	}
}

void Student::modInfo()
{
	cout << "field need to modify: " << endl
		<< "1.ID 2.Name 3.Birthday 4.Grade 5.Number of Project and score of each project" << endl;
	int choice;
	float s[50];
	cin >> choice;
	Date a;
	switch (choice) {
	case 1:
		cout << "ID: ";
		int id;
		cin >> id;
		this->SetID(id);
		break;
	case 2:
		cout << "Name: ";
		cin.clear();
		rewind(stdin);
		char name[50];
		gets_s(name, 50);
		this->SetName(name);
		break;
	case 3:
		cout << "day: ";
		cin >> a.Day;
		cout << "month: ";
		cin >> a.Month;
		cout << "year: ";
		cin >> a.Year;
		this->SetBirthday(a);
		break;
	case 4:
		cout << "grade: ";
		int grade;
		cin >> grade;
		this->SetGrade(grade);
		break;
	case 5:
		cout << "Number of project: ";
		int num;
		cin >> num;
		this->SetNumofProject(num);
		for (int i = 0; i < num; i++) {
			cout << "Score[" << i << "] = ";
			cin >> s[i];
		}
		this->SetScore(s);
		break;
	default:
		cout << "don't have this choice!" << endl;
	}
}

float Student::CalculateAvrScore()
{
	if (Score == NULL) return 0;
	float tb = 0;
	for (int i = 0; i < NumofProject; i++) {
		tb += Score[i];
	}
	return tb / NumofProject;
}

////test
//int main() {
//	Date d(9, 5, 1997);
//	Student a(1,"nguyen phuc chuong",d,12,3);
//	float score[] = { 6.6,5.5,8.5 };
//	a.PrintInfo();
//	a.SetScore(score);
//	cout << endl;
//	a.PrintInfo();
//	return 0;
//}