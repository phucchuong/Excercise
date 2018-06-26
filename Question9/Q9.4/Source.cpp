#include<iostream>
using namespace std;
extern "C" {
	void sort(int *arr, int count, int(*order) (int, int));
}

int CheckBigger(int a, int b) { return a>b; }
int CheckSmaller(int a, int b) { return a<b; }

int main() {

	int a[] = { 6,5,4,-5,3,-11,15 };
	for (int i = 0; i < sizeof(a) / 4; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	sort(a, sizeof(a) / 4, CheckSmaller);

	for (int i = 0; i < sizeof(a) / 4; i++) {
		cout << a[i] << " ";
	}
	cout << endl;

	return 0;
}