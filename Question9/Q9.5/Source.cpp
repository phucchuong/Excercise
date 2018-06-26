#include<iostream>
using namespace std;

class ClassA
{
public:
	ClassA(int val = 0) { m_pVal = val; }
	int m_pVal;
};
void Todo1(ClassA *A, ClassA *B)
{
	ClassA *tmp = A;
	A = B;
	B = tmp;
}
void Todo2(ClassA &A, ClassA &B)
{
	ClassA tmp = A;
	A = B;
	B = tmp;
}

void Todo3(ClassA A, ClassA B)
{
	ClassA tmp = A;
	A = B;
	B = tmp;
}	
void Todo4(ClassA *&A, ClassA *&B)
{
	ClassA *tmp = A;
	A = B;
	B = tmp;
}

void main()
{
	ClassA *A = new ClassA(10);
	ClassA B(0);
	ClassA *C = &B;
	cout << A << " " << &B << " " << C << endl;
	printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
	Todo1(A, &B);
	cout << A << " " << &B << " " << C << endl;
	printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
	Todo2(*A, B);
	cout << A << " " << &B << " " << C << endl;
	printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
	Todo3(*A, B);
	cout << A << " " << &B << " " << C << endl;
	printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
	Todo4(A, C);
	cout << A << " " << &B << " " << C << endl;
	printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
}
