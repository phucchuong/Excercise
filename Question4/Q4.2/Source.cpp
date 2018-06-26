#include<iostream>
using namespace std;

void use_memcpy(int a[], int b[], int c[]);
void without_memcpy(int a[], int b[], int c[]);
void show(int a[], int n);

int main(int argc, char ** argv) {
	int a[10] = { 0,2,4,5,3,6,5,8,4,9 };
	int b[10] = { 5,6,4,7,8,2,26,5,4,8 };
	int c[20] = { 0 };
	use_memcpy(a, b, c);
	//without_memcpy(a, b, c);
	show(a, 10);
	show(b, 10);
	show(c, 20);
	system("pause");
	return 0;
}

void use_memcpy(int a[], int b[], int c[]) {
	memcpy(c, a, sizeof(int)*10);
	memcpy(c + 10, b, sizeof(int) * 10);
}

void without_memcpy(int a[], int b[], int c[])
{
	for (register int i = 0; i < 10; i++) {
		c[i] = a[i];
		c[10 + i] = b[i];
	}
}


void show(int a[], int n) {
	for (register int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
