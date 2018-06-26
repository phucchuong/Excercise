#include"Stack.h"
#include"Stack.cpp"

// Q12.2: demo with stack of integer
int main() {
	Stack<int> a(10);
	a.push(9);
	a.push(8);
	a.push(7);
	a.push(5);
	a.push(4);
	a.push(3);
	a.push(2);
	a.push(1);
	a.push(0);
	int x;
	while (!a.isEmpty()) {
		cout << a.pop()<<" "; // print from 0 to 9
	}
	return 0;
}