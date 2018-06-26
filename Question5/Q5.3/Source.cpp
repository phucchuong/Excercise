#include<iostream>
#include<iomanip>
using namespace std;

int main() {
	int x = 3, y = 8, z = 6;
	int *p = &x, *q = &y, *r = &z;
	cout << "x = " << setw(15) << left << x
		<< "y = " << setw(15) << left << y
		<< "z = " << setw(15) << left << z << endl;
	cout << "p = " << setw(15) << left
		<< p << "q = " << setw(15) << left
		<< q << "r = " << setw(15) << left << r << endl;
	cout << "*p = " << setw(14) << left
		<< *p << "*q = " << setw(14) << left
		<< *q << "*r = " << setw(14) << left << *r << endl;
	cout << "\nSwapping values: z = x; x = y; y = z;\n" << endl;
	z = x; x = y; y = z;
	cout << "x = " << setw(15) << left
		<< x << "y = " << setw(15) << left
		<< y << "z = " << setw(15) << left << z << endl;
	cout << "p = " << setw(15) << left
		<< p << "q = " << setw(15) << left
		<< q << "r = " << setw(15) << left << r << endl;
	cout << "*p = " << setw(14) << left
		<< *p << "*q = " << setw(14) << left
		<< *q << "*r = " << setw(14) << left << *r << endl;
	system("pause");
	return 0;
}