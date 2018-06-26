#include<iostream>
using namespace std;

namespace V {
	enum Vertical_Align { LEFT = 2, CENTER = 4, RIGHT = 6 };
}

namespace H {
	enum Horizontal_Align { TOP = 3, CENTER = 6, BOTTOM = 9 };
}

using namespace H;
using namespace V;

void checkAlignment_Vertical(int x) {
	switch (x) {
	case LEFT:
		cout << "Alignment is " << LEFT << endl;
		break;
	case V::CENTER:
		cout << "Alignment is " << V::CENTER << endl;
		break;
	case RIGHT:
		cout << "Alignment is " << RIGHT << endl;
		break;
	}
}

void checkAlignment_horizontal(int x) {
	switch (x) {
	case TOP:
		cout << "Alignment is " << TOP << endl;
		break;
	case H::CENTER:
		cout << "Alignment is " << H::CENTER << endl;
		break;
	case BOTTOM:
		cout << "Alignment is " << BOTTOM << endl;
		break;
	}
}

int main() {
	Horizontal_Align horizontal = H::CENTER;
	Vertical_Align vertical= V::CENTER;
	checkAlignment_horizontal(horizontal);
	checkAlignment_Vertical(vertical);
	return 0;
}