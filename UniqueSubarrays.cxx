#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	if (n > 3) {
		cout << "-1\n";
	}
	else if (n == 3) {
		cout << "1 3 2\n";
	}
	else if (n == 2) {
		cout << "1 2\n";
	}
	else {
		cout << "1\n";
	}
	
	
	return 0;
}

