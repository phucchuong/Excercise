#include<iostream>
using namespace std;

void Invert(int input[], int num_element);
void Invert(int input[], int num_element,int output[]);
void Show(int arr[],int n);

int main(int argc, char **argv) {
	int a[10] = { 0,2,4,5,3,6,5,8,4,9 };
	int b[10];
	Show(a,10);
	Invert(a, 10);
	Show(a,10);
	Invert(a, 10, b);
	Show(b, 10);
	system("pause");
	return 0;
}

void Invert(int input[], int num_element)
{
	int n = num_element / 2,temp;
	for (register int i = 0; i <= n; i++) {
		temp = input[i];
		input[i] = input[num_element - i - 1];
		input[num_element - i - 1] = temp;
	}
}

void Invert(int input[], int num_element, int output[])
{
	for (register int i = 0; i < num_element; i++) {
		output[num_element - 1 - i] = input[i];
	}
}

void Show(int arr[], int n)
{
	for (register int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	cout << endl;
}