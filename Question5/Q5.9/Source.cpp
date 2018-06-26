#include<iostream>
using namespace std;

void main()
{
	int *a = new int;
	*a = 10;
	
	printf("%d", *a);delete a;
}
