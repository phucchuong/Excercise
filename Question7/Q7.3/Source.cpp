#include<cstdio>

union MyUnion
{
	int iVal;
	float fVal;
	char cVal[4];
};

void main()
{
	union MyUnion u;
	u.fVal = 100;
	printf("%d\n%f\n%d\n%d\n", u.iVal, u.fVal, u.cVal[0], sizeof(u));
}