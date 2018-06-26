#include<iostream>
#include<ctime>
#include<Windows.h>
using namespace std;

int main() {
	clock_t begin, end;
	time_t timer;
	while (1) {
		begin = clock();
		system("cls");
		timer = time(NULL);
		struct tm ptm;
		gmtime_s(&ptm, &timer);
		cout << (ptm.tm_hour + 7 < 10 ? "0" : "")
			<< (ptm.tm_hour + 7) % 24<< ":" 
			<< (ptm.tm_min < 10 ? "0" : "")
			<< ptm.tm_min << ":" 
			<< (ptm.tm_sec < 10 ? "0" : "")
			<< ptm.tm_sec << endl;
		end = clock();

		Sleep(200 - (end - begin));
	}
	return 0;
}