#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		int a, b, works=0;
		cin >> a >> b;
		
		if (b == 1 && a >= 7) {
			works = 1;
		}
		if (b >= 2 && a >= 4) {
			works = 1;
		}
		if (a >= 2 && b >= 4) {
			works = 1;
		}
		
		if (works) {
			cout << "good\n";
		}
		else {
			cout << "bad\n";
		}
	}
	
	return 0;
}

