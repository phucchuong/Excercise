#include<iostream>
#include<string>
using namespace std;
#pragma warning(disable : 4996)
// bo qua yeu cau dung ham strncpy_s()
#define Min(m,n) m>n?n:m
void copyString_memcpy(char *input, int offset, int lenght, bool invert, char *output, int output_offset);
void copyString_strcpy(char *input, int offset, int lenght, bool invert, char *output, int output_offset);
void copyString(char *input, int offset, int lenght, bool invert, char *output, int output_offset);
void Swap(char &a, char &b);

int main() {
	char st[] = "Hello world", st2[] = "My name is C++";

	cout << st << endl;
	cout << st2 << endl;
	copyString_strcpy(st, 6, 5, false, st2, 11);
	cout << st2 << endl;
	return 0;
}

void copyString_memcpy(char * input, int offset, int lenght, bool invert, char * output, int output_offset)
{
	if (invert) {
		//copy phan cuoi cua chuoi
		int n = (strlen(output) - output_offset);
		n = (Min(n,lenght));
		int m = (strlen(input) - offset);
		memcpy(output + output_offset, input + offset + m - (Min(m, n)), Min(m, n));
		// dao chuoi
		for (register int i = 0; i <= (Min(m, n))/2; i++) {
			Swap(output[output_offset + i], output[output_offset + n - i-1]);
		}
	}
	else {
		// số byte cần copy phải nhỏ hơn số byte tính từ output_offset đến kí tự '/0'
		int n = (strlen(output) - output_offset);
		n = n > lenght ? lenght : n;
		int m = (strlen(input) - offset);
		memcpy(output + output_offset, input + offset, Min(m, n));
	}
}

void copyString_strcpy(char * input, int offset, int lenght, bool invert, char *output, int output_offset)
{
	if (invert) {
		//copy phan cuoi cua chuoi
		int n = (strlen(output) - output_offset);
		n = (Min(n, lenght));
		int m = (strlen(input) - offset);
		strncpy(output + output_offset, input + offset + m - (Min(m, n)), Min(m, n));
		// dao chuoi
		for (register int i = 0; i <= (Min(m, n)) / 2; i++) {
			Swap(output[output_offset + i], output[output_offset + n - i - 1]);
		}
	}
	else {
		int n = strlen(output) - output_offset;
		n = (Min(n, lenght));
		int m = strlen(input) - offset;
		cout << strlen(output) << endl;
		strncpy(output + output_offset, input + offset, Min(m, n));	
	}
}

void copyString(char * input, int offset, int lenght, bool invert, char * output, int output_offset)
{
	if (invert) {
		for (register int i = 0; i < lenght; i++) {
			if (output[output_offset + lenght - 1 - i] && input[offset + i])
				output[output_offset + lenght - 1 - i] = input[offset + i];
			else
				break;
		}
	}
	else {
		for (register int i = 0; i < lenght; i++) {
			if (output[output_offset + i] && input[offset + i])
				output[output_offset + i] = input[offset + i];
			else
				break;
		}
	}
}

void Swap(char &a, char &b)
{
	char temp = a;
	a = b;
	b = temp;
}
