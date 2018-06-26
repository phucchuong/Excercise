#include<iostream>
using namespace std;

int main() {
	char *st1 = "Hello world";
	char st2[] = { 'H','e','l','l','o',' ','w','o','r','l','d','\0'};
	char *st3 = new char[12];
	//c1
	//memcpy(st3, "Hello world", 12);
	//c2
	strcpy_s(st3,sizeof("Hello world"), "Hello world");
	cout << st1 << endl;
	cout << st2 << endl;
	cout << st3 << endl;
	return 0;
}