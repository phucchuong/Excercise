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
	// hàm todo1 nhân các đối số là các con trỏ, 
	//nhưng các con trỏ này là bản sao của các đối tượng truyền vào,
	//nên khi thực hiện xong bộ nhớ được giải phóng => không thay đổi gì
	cout << A << " " << &B << " " << C << endl;
	printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
	Todo2(*A, B);
	// hàm todo2 có các đối só tuyền vào là tham chiếu => có thể thực hiện thay đổi cùng nhớ nhưng không thể thay đổi địa chỉ
	cout << A << " " << &B << " " << C << endl;
	printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
	Todo3(*A, B);
	// truyền vào tham trị => khi thực hiện xong thì bộ nhớ bị giải phóng => không thay đổi gì
	cout << A << " " << &B << " " << C << endl;
	printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
	Todo4(A, C);
	// todo4 truyền vào là tham chiếu con trỏ nên cả địa chỉ và cùng nhớ điều bị thay đổi.
	cout << A << " " << &B << " " << C << endl;
	printf("%d %d %d\n", A->m_pVal, B.m_pVal, C->m_pVal);
}
