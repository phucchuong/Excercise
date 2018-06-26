#include<iostream>
using namespace std;
#include<string>
float div(float a, float b);
float averageofList(int count, int offset, float *arr);

int main() {
	float a = 10.5, b = 1.6, c = 0,kq;
	/*try {
		kq = div(a,c);
		cout << kq << endl;
	}
	catch (string &s) {
		cout << s << endl;
	}

	*/
	float arr[] = { 1.2,2.5,2.6,2.5,2,9,9.8,4,7.8,9.3 };
	
	try {
		kq=averageofList(5, 4, arr);
		cout << kq << endl;
	}
	catch (string s) {
		cout << s << endl;
	}

	return 0;
}

float div(float a, float b)
{
	if (b == 0) throw (string("err divide by zero !"));
	else
	return a/b;
}

float averageofList(int count, int offset, float* arr) {
	if (offset > count) throw string("out of bound !");
	else {
		float kq=0;
		for (int i = offset; i < count; i++) {
			kq += arr[i];
		}
		return div(kq,(float)(count-offset));
	}
}