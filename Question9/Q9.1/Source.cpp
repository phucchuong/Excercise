#include<iostream>
#include<stdio.h>
#include<cstdarg>
using namespace std;

void show(char *const a, int num_param, ...) {
	va_list marker;
	va_start(marker, num_param);
	if (a == "%ud") {
		for (register int i = 0; i < num_param; i++) {
			printf("%d ", va_arg(marker, int));
		}
	}
	else {
		for (register int i = 0; i < num_param; i++) {
			printf("%u ", va_arg(marker, unsigned int));
		}
	}
	va_end(marker);
}

int main() {
	show("%ud", 6, 5, 6, -8, -6, 5, -7);
	printf("\n");
	show("%sd", 6, 5, 6, -8, -6, 5, -7);
	return 0;
}