#include <iostream>
#include <vector>

using namespace std;

int main() {
	string s;
	cin >> s;
	
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	for (int i = 0; i < 26; i ++) {
		bool works = 1;
		for (int j = 0; j < 5; j ++) {
			if (alphabet[i] == s[j]) {
				works = false;
			}
		}
		if (works) {
			cout << alphabet[i] << "\n";
			break;
		}
	}
	
	return 0;
}

