#include<iostream>
using namespace std;
#define max 100

void BubbleSort(int arr[], int offset, int count);
void Show(int a[], int n);

int main(int argc, char **argv) {
	int a[max];
	int n, offset;
	cout << "nhap so luong phan tu : n = ";
	cin >> n;
	for (register int i = 0; i < n; i++) {
		cout << "nhap phan tu thu " << i + 1 << " : ";
		cin >> a[i];
	}
	do {
		cout << "nhap vi tri bat dau sap xep (offset<n): offset = ";
		cin >> offset;
	} while (offset > n);
	Show(a, n);
	BubbleSort(a, offset, n);
	Show(a, n);
	system("pause");
	return 0;
}

void BubbleSort(int arr[], int offset, int count)
{
	int temp;
	for (register int i = offset; i < count - 1; i++) {
		for (register int j = i + 1; j < count; j++) {
			if (arr[j] < arr[j-1]) {
				temp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = temp;
			}
		}
	}
}

void Show(int a[], int n)
{
	for (register int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}
