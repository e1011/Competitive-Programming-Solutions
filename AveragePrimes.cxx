#include <iostream>

using namespace std;

bool checkifprime(int n) {
	for (int i = 2; i*i <= n; i ++) {
		if (n % i == 0) {
			return false;
		}
	}
	return true;
}

int main() {
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i ++) {
		int n;
		cin >> n;
		
		int increment = 0;
		while (true) {
			if (checkifprime(n-increment) && checkifprime(n+increment)) {
				cout << n-increment << " " << n+increment << "\n";
				break;
			}
			increment += 1;
		}
	}
	
	return 0;
}

