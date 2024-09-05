#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int _ = 0; _ < t; _ ++) {
		string s;
		cin >> s;
		
		if (s == "()") {
			cout << "NO\n";
			continue;
		}
		
		int counter = 0;
		for (int i = 1; i < s.size(); i ++) {
			if (s[i-1] == '(' && s[i] == ')') {
				counter += 1;
			}
			if (s[i-1] == ')' && s[i] == '(') {
				counter += 2;
			}
		}
		
		cout << "YES\n";
		if (counter < 2) {
			for (int i = 0; i < s.size(); i ++) {
				cout << "()";
			}
		}
		else {
			for (int i = 0; i < s.size(); i ++) {
				cout << '(';
			}
			for (int i = 0; i < s.size(); i ++) {
				cout << ')';
			}
		}
		cout << "\n";
	}
	
	return 0;
}

