#include<iostream>
#include<ctime>
using namespace std;

char *DoW[] = { "Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday" };

struct Date {
	unsigned char Day0fWeek, Day, Month;
	unsigned int Year;
};

void showDate(const Date &date) {
	cout << DoW[date.Day0fWeek] << ", " 
		<<(date.Day<10?"0":"")<<(int) date.Day << "-" 
		<< (date.Month<10 ? "0" : "") << (int)date.Month+1 
		<< "-" << date.Year << endl;

	cout << (date.Day<10 ? "0" : "") << (int)date.Day
		<< "/" << (date.Month<10 ? "0" : "") << (int)date.Month
		<< "/" << date.Year  << endl;

	cout << (date.Day<10 ? "0" : "") << (int)date.Day
		<< "-" << (date.Month<10 ? "0" : "") << (int)date.Month
		<< "-" << date.Year << endl;

	cout << DoW[date.Day0fWeek] << " "
		<< (date.Day<10 ? "0" : "") << (int)date.Day 
		<< "."<< (date.Month<10 ? "0" : "") << (int)date.Month
		<< "." << date.Year%100 << endl;
}

#pragma warning(disable: 4996)

int main() {
	Date date;
	tm *ptm;
	time_t stime;
	stime = time(NULL);
	ptm = gmtime(&stime);
	date.Day = ptm->tm_mday;
	date.Day0fWeek = ptm->tm_wday;
	date.Month = ptm->tm_mon+1;
	date.Year = ptm->tm_year+1900;
	showDate(date);

	return 0;
}