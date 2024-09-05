#include <iostream>

using namespace std;

int main() {
	long long n, a=0, d=0;
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		if (x % 2 == 0) {
			d += x/2;
		}
		else {
			a += (x+1)/2;
		}
	}
	
	if (a >= d) {
		cout << "Alice\n";
	}
	else {
		cout << "Duke\n";
	}
	
	return 0;
}

