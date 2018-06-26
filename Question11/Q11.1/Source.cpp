#include<iostream>
using namespace std;

template<class R, class T>R Average(int count, T* list);

int main() {
	int a[] = { 1,2,3,4,5,6 };
	float b[] = { 1.2,2.3,2.5,5.9,8.7,9.2 };
	double c[] = { 1.2326,2.3564,3.646,9.64256,8.151,1.1519 };
	cout << "trung binh a: " << Average<int, int>(6, a) << endl;
	cout << "trung binh a: " << Average<float, int>(6, a) << endl;
	cout << "trung binh b: " << Average<int, float>(6, b) << endl;
	cout << "trung binh b: " << Average<float, float>(6, b) << endl;
	cout << "trung binh c: " << Average<int, double>(6, c) << endl;
	cout << "trung binh c: " << Average<float, double>(6, c) << endl;
	return 0;
}

template<class R, class T>
R Average(int count, T * list)
{
	if (count == 0) return 0;
	R avr=0;
	for (int i = 0; i < count; i++) {
		avr += list[i];
	}
	return avr/count;
}
