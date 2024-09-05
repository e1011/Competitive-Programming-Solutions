#include <iostream>

using namespace std;

int main() {
	int n, counter=0;
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		if ((i/2) % 2 != 0) {
			counter += 1;
		}
	}
	cout << counter << "\n";
	for (int i = 0; i < n; i ++) {
		if ((i/2) % 2 == 0) {
			cout << "_";
		}
		else {
			cout << "M";
		}
	}
	cout << "\n";
	
	return 0;
}

