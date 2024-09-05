#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	string alphabet = "abcdefghijklmnopqrstuvwxyz", s;
	int n;
	
	cin >> n >> s;
	
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] == '*') {
			n -= 1;
		}
		else {
			n -= alphabet.find(s[i]) + 1;
		}
	}
	
	reverse(s.begin(), s.end());
	for (int i = 0; i < s.size(); i ++) {
		if (s[i] == '*') {
			if (n >= 25) {
				s[i] = 'z';
				n -= 25;
			}
			else if (n == 0) {
				s[i] = 'a';
			}
			else if (n > 0 && n < 25) {
				s[i] = alphabet[n];
				n = 0;
			}
		}
	}
	
	if (n == 0) {
		reverse(s.begin(), s.end());
		cout << s << "\n";	
	}
	else {
		cout << "Impossible\n";
	}
	
	return 0;
}

