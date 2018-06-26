#include<iostream>
using namespace std;

int count_no_function;

//su dung bien toan cuc
void global_variable() {
	count_no_function++;
}

// su dung bien tinh cuc bo
int static_variable_inside() {
	static int sta_va_in;
	return ++sta_va_in;
}

// su dung bien tinh o ngoai ham
void static_variable_outside(int &a) {
	a++;
}

int main() {
	static int sta_va_out;
	int sta_va_in = 0;
	cout << "so lan goi ham global_variable : " << count_no_function << endl;
	cout << "so lan goi ham static_variable_inside : " << sta_va_in << endl;
	cout << "so lan goi ham static_variable_outside : " << sta_va_out << endl;
	global_variable();
	sta_va_in=static_variable_inside();
	static_variable_outside(sta_va_out);
	cout << "so lan goi ham global_variable : " << count_no_function << endl;
	cout << "so lan goi ham static_variable_inside : " << sta_va_in << endl;
	cout << "so lan goi ham static_variable_outside : " << sta_va_out << endl;
	return 0;
}