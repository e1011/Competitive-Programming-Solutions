#include <iostream>

using namespace std;

int main() {
	long long n, m;
	cin >> n >> m;
	
	if (n % 2 == 0 || m % 2 == 0) {
		cout << (n*m)/2 << " " << (n*m)/2 << "\n";
	}
	else {
		if (n < m) {
			swap(n, m);
		}
		cout << (n/2 + 1)*m << " " << (n/2)*m << "\n";
	}
	
	return 0;
}

