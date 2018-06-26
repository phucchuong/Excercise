#include<iostream>
#include<iomanip>
using namespace std;
#define max 10
#pragma warning(disable: 4996)
struct Student {
	char Name[30];
	int Id;
	float Score;
	Student(char name[]="", int id=0, float score=0);
	void show();
};
void Input(Student s[], int sl);
void sort(Student s[], int sl);

int main() {
	Student Class[max];
	int sl = 4;
	Input(Class, sl);
	cout << "*** Danh sach sinh vien ***" << endl;
	for (int i = 0; i < sl; i++)
		Class[i].show();
	cout << "sap xep giam dan theo diem " << endl;
	sort(Class, sl);
	for (int i = 0; i < sl; i++)
		Class[i].show();
	return 0;
}

void Input(Student s[], int sl)
{
	for (int i = 0; i < sl; i++) {
		bool check;
		do {
			check = false;
			cout << "Nhap id: ";
			cin >> s[i].Id;
			for (int j = 0; j < i; j++) {
				if (s[j].Id == s[i].Id) {
					cout << "id sinh vien da ton tai" << endl;
					check = true;
					break;
				}
			}
		} while (check);
		cout << "Nhap ten: ";
		rewind(stdin);
		gets_s(s[i].Name, 30);
		do {
			cout << "Nhap diem: ";
			cin >> s[i].Score;
		} while (s[i].Score < 0 || s[i].Score>10);
	}
}

Student::Student(char name[], int id, float score)
{
	strcpy(Name, name);
	Id = id;
	Score = score;
}

void Student::show()
{
	cout << setw(6) <<left<< Id << setw(30) << left << Name << setw(4) << Score << endl;
}

void sort(Student s[], int sl)
{
	for (int i = 0; i < sl - 1; i++) {
		for (int j = sl-1; j >i; j--) {
			if (s[j].Score > s[j - 1].Score) {
				Student a = s[j];
				s[j] = s[j - 1];
				s[j - 1] = a;
			}
		}
	}
}
