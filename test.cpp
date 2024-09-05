#include <iostream>
#include <vector>
#include <random>

using namespace std;

int main() {
	string alphabet = "abcdefghijklmnopqrstuvwxyz", alphabet2 = "abcdefghijklmnopqrstuvwxyz", s;
	cin >> s;
	
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		char a, b;
		cin >> a >> b;
		for (int j = 0; j < 26; j ++) {
			if (alphabet[j] == a) {
				alphabet[j] = b;
			}
		}
	}
	
	for (int i = 0; i < s.size(); i ++) {
		for (int j = 0; j < 26; j ++) {
			if (s[i] == alphabet2[j]) {
				counter += 1;
				s[i] = alphabet[j];
			}
		}
	}
	
	/*
	for (int i = 0; i < n; i ++) {
		char a, b;
		cin >> a >> b;
		for (int j = 0; j < s.size(); j ++) {
			if (s[j] == a) {
				s[j] = b;
			}
		}
	}
	* */
	
	cout << s << "\n";
    
    return 0;
}
