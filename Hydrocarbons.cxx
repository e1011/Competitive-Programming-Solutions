#include <iostream>

using namespace std;

int main() {
	int a, b, c, d, works=1;
	cin >> a >> b >> c >> d;
	
	if ((2*a+4*b+6*c+d) % 4 == 0 && (2*a+4*b+6*c+d)/4 == (a+b+c+1)) {
		
	}
	else {
		works = false;
	}
	
	if (works) {
		cout << "C" << (2*a+4*b+6*c+d)/4 << "H" << d << "\n";
	}
	
	return 0;
}

