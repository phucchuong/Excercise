#include<iostream>
#include<ctime>
using namespace std;

char *DoW[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };

struct Date {
	unsigned char Day0fWeek, Day, Month;
	unsigned int Year;
	void showDate();
	Date(unsigned char dow = 1, unsigned char day = 1, unsigned char month = 1, int year = 2000);
	bool checkValidDate();
};

#pragma warning(disable: 4996)

int main() {
	Date date(5, 9, 5, 1997);
	if (date.checkValidDate())
		date.showDate();
	else
		cout << "ngay nhap vao khong chinh xac !" << endl;
	return 0;
}

void Date::showDate()
{

	cout << DoW[Day0fWeek] << ", "
		<< (Day < 10 ? "0" : "") << (int)Day << "-"
		<< (Month < 10 ? "0" : "") << (int)Month
		<< "-" << Year << endl;

	cout << (Day < 10 ? "0" : "") << (int)Day
		<< "/" << (Month < 10 ? "0" : "") << (int)Month
		<< "/" << Year << endl;

	cout << (Day < 10 ? "0" : "") << (int)Day
		<< "-" << (Month < 10 ? "0" : "") << (int)Month
		<< "-" << Year << endl;

	cout << DoW[Day0fWeek] << " "
		<< (Day < 10 ? "0" : "") << (int)Day
		<< "." << (Month < 10 ? "0" : "") << (int)Month
		<< "." << (Month < 10 ? "0" : "") << Year % 100 << endl;

}

Date::Date(unsigned char dow, unsigned char day, unsigned char month, int year)
{
	Day0fWeek = dow;
	Day = day;
	Month = month;
	Year = year;
}

bool Date::checkValidDate()
{
	if (Day0fWeek > 6 || Day > 31 || Month > 12) return false;
	return true;
}
