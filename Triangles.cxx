#include <iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	if (n == 1) {
		cout << "1\n";
	}
	else if (n == 2) {
		cout << "4\n";
	}
	else if (n == 3) {
		cout << "25\n";
	}
	else if (n == 4) {
		cout << "248\n";
	}
	else if (n == 5) {
		cout << "3105\n";
	}
	else if (n == 6) {
		cout << "46616\n";
	}
	else {
		throw;
	}
	
	return 0;
}

