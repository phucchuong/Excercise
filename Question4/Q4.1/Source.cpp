#include<iostream>
using namespace std;
#define n 10

int count(int a[]) {
	int dem = 0;
	for (register int i = 0; i < n; i++) {
		if (a[i] >= 10) dem++;
	}
	return dem;
}

int main(int argc , char** argv) {
	int array[n];
	for (register int i = 0; i < n; i++) {
		cout << "Nhap so thu " << i + 1 << " : ";
		cin >> array[i];
	}
	cout << "So phan tu >= 10 la : " << count(array) << endl;
	system("pause");
	return 0;
}