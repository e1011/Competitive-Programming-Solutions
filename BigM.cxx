#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	n %= 6;
	
	if (n == 1) {
		cout << "3\n";
	}
	if (n == 2) {
		cout << "2\n";
	}
	if (n == 3) {
		cout << "6\n";
	}
	if (n == 4) {
		cout << "4\n";
	}
	if (n == 5) {
		cout << "5\n";
	}
	if (n == 0) {
		cout << "1\n";
	}
	
	return 0;
}

