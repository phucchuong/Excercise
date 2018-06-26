#include<iostream>
#include<stdio.h>
using namespace std;

void show(char *const a) {
	printf("%u\n", a);
	printf("%s\n", a);
}

int main() {
	char *a = "chuong";
	show(a);
	return 0;
}