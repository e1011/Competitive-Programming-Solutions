#include <iostream>

using namespace std;

int main() {
	int n, c;
	cin >> n >> c;
	
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		cout << x+2*c;
		if (i == n-1) {
			cout << "\n";
		}
		else {
			cout << " ";
		}
	}
	
	return 0;
}

