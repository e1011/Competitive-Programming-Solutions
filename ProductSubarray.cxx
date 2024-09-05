#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, three;
	cin >> n;
	vector <int> arr(n, 0);
	
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		if (arr[i] == 3) {
			three = i+1;
		}
	}
	
	if (n == 1) {
		cout << 1 << " " << 1 << "\n";
	}
	else if (arr[0] == 1) {
		cout << 2 << " " << n << "\n";
	}
	else if (arr[n-1] == 1) {
		cout << 1 << " " << n-1 << "\n";
	}
	else if (n == 3) {
		cout << three << " " << three << "\n";
	}
	else {
		cout << 1 << " " << n << "\n";
	}
	
	return 0;
}

