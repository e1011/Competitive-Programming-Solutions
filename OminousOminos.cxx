#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i ++) {
		int x, r, c;
		cin >> x >> r >> c;
		
		cout << "Case #" << i+1 << ": ";
		if (r*c % x) {
			cout << "RICHARD\n";
			continue;
		}
		if (min(r, c) < (x+1)/2) {
			cout << "RICHARD\n";
			continue;
		}
		if (max(r, c) < x) {
			cout << "RICHARD\n";
			continue;
		}
		if (x > 6) {
			cout << "RICHARD\n";
			continue;
		}
		if (x == 4 && min(r, c) == 2) {
			cout << "RICHARD\n";
			continue;
		}
		if (x == 5 && min(r, c) == 3) {
			cout << "RICHARD\n";
			continue;
		}		
		if (x == 6 && min(r, c) == 3) {
			cout << "RICHARD\n";
			continue;
		}
		if (x == 6 && min(r, c) == 4 && max(r, c) == 6) {
			cout << "RICHARD\n";
			continue;
		}
		cout << "GABRIEL\n";
		
	}
	
	
	return 0;
}

