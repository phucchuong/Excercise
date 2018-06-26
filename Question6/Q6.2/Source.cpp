#include<iostream>
using namespace std;

void clone(char *input, char *output);

int main() {
	char *a = "chuong np", b[256];
	clone(a, b);
	cout << a << endl << b << endl;
	return 0;
}

void clone(char * input, char * output)
{
	int n = strlen(input);
	for (int i = 0; i <= n; i++) {
		output[i] = input[i];
	}
}
