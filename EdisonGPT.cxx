#include <iostream>

using namespace std;

int main() {
	int a, b=0, c=0;
	cin >> a;
	string s;
	while (b < a) {
		cin >> s;
		b += s.size() + 1;
		for (int i = 0; i < s.size(); i ++) {
			if (s[i] == 'e' || s[i] == 'E') {
				c += 1;
			}
			else if (s[i] == 'a' || s[i] == 'A' || s[i] == 'i' || s[i] == 'I' || s[i] == 'o' || s[i] == 'O' || s[i] == 'u' || s[i] == 'U') {
				c -= 1;
			}
		}
	}
	
	if (c <= 0) {
		cout << "great work!\n";
	}
	else {
		cout << "see me after class...\n";
	}
	
	return 0;
}

