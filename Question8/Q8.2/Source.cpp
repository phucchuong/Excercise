#include<iostream>
#include<ctime>
using namespace std;

struct Date {
	unsigned char Day0fWeek, Day, Month;
	unsigned int Year;
};

int main() {
	Date date = { 1,18,6,2018 };
	cout<<sizeof(Date) << endl;
	cout << sizeof(date) << endl;
	return 0;
}