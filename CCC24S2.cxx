#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t, n;
	cin >> t >> n;
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	
	for (int _ = 0; _ < t; _ ++) {
		string s;
		vector <int> lettercounts(26, 0);
		vector <int> arrcount(n, 0);
		cin >> s;
		
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < 26; j ++) {
				if (alphabet[j] == s[i]) {
					lettercounts[j] += 1;
				}
			}
		}
		
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < 26; j ++) {
				if (s[i] == alphabet[j]) {
					arrcount[i] = lettercounts[j];
				}
			}
		}
		
		for (int i = 0; i < n; i ++) {
			arrcount[i] = (arrcount[i] > 1);
		}
		
		bool works = 1;
		for (int i = 1; i < n; i ++) {
			if (arrcount[i] == arrcount[i-1]) {
				works = 0;
			}
		}
		if (works) {
			cout << "T\n";
		}
		else {
			cout << "F\n";
		}
	}
	
	
	return 0;
}

