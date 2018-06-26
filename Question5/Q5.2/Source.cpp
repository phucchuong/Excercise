#include<iostream>
using namespace std;

int main() {
	int x = 2, y = 8;
	int *p = &x, *q = &y;
	//1. the address of x and the value of x
	cout << "&x = 0x" << &x <<"		x = " << x << endl;
	//2. the calue of p and the value of *p
	cout << "p = 0x" << p << "		*p = " << *p << endl;
	//3. the address of y and the value of y
	cout << "&y = 0x" << &y << "		y = " << y << endl;
	//4. the calue of q and the value of *q
	cout << "q = 0x" << q << "		*q = " << *q << endl;
	//5. the address of p (not its contents!)
	cout << "&p = 0x" << &p << endl;
	//6. thw address of q (not its contents!)
	cout << "&q = 0x" << &q << endl;
	system("pause");
	return 0;
}