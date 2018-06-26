#include<iostream>
using namespace std;

int main() {
	int *a, *b;
	a = new int;
	b = new int[10];
	*a = 1;
	b[0] = 1;
	delete a;
	delete[]b;
	return 0;
}