#include<iostream>
#include<ctime>
using namespace std;

#define MAX 10000

int main() {
	clock_t begin, end;
	begin = clock();
	for (register int i = 0; i < MAX; i++)
	{
		for (register int j = 0; j < MAX; j++)
		{
			for (register int k = 0; k < MAX; k++)
			{
			}
		}
	}
	end = clock();
	cout << "thoi gian : " << (end - begin) <<" ms"<< endl;
	system("pause");
	return 0;
}