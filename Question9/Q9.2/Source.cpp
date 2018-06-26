#include<iostream>
using namespace std;

void SayHello();
void SayHello(char *s);
void SayHello_i(char *s, bool invert = false);
void Swap(char &a, char &b);

int main() {
	char s[] = "nguyen phuc chuong";
	SayHello();
	SayHello(s);
	SayHello_i(s, true);
	return 0;
}

void SayHello()
{
	cout << "Hello world" << endl;
}

void SayHello(char * s)
{
	cout << "Hello world" << endl;
	cout << s << endl;
}

void Swap(char &a, char &b) {
	char temp = a;
	a = b;
	b = temp;
}

void SayHello_i(char * s, bool invert)
{
	cout << "Hello world" << endl;
	if (invert) {
		int len = strlen(s)-1;
		for (int i = 0; i <= len / 2; i++) {
			Swap(s[i], s[len - i]);
		}
		cout << s << endl;
	}
	else {
		cout << s << endl;
	}
}
