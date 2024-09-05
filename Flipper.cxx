#include <iostream>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	int v=0, h=0;
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] == 'H') {
			v += 1;
		}
		else {
			h += 1;
		}
	}
	
	v %= 2;
	h %= 2;
	if (v == 0 && h == 0) {
		cout << 1 << " " << 2 << "\n" << 3 << " " << 4 << "\n";
	}
	if (v == 1 && h == 0) {
		cout << 3 << " " << 4 << "\n" << 1 << " " << 2 << "\n";
	}
	if (v == 0 && h == 1) {
		cout << 2 << " " << 1 << "\n" << 4 << " " << 3 << "\n";
	}
	if (v == 1 && h == 1) {
		cout << 4 << " " << 3 << "\n" << 2 << " " << 1 << "\n";
	}
	
	return 0;
}

