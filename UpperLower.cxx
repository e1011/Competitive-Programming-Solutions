#include <iostream>
#include <vector>

using namespace std;

int main() {
	string s, alphabet = "abcdefghijklmnopqrstuvwxyz";
	cin >> s;
	
	int ans = 0, index;
	vector <int> freq(26, 0);
	
	for (int i = 0; i < s.size(); i ++) {
		for (int j = 0; j < 26; j ++) {
			if (alphabet[j] == s[i]) {
				freq[j] += 1;
				if (freq[j] > ans) {
					ans = freq[j];
					index = j;
				}
				if (freq[j] == ans) {
					if (j < index) {
						ans = freq[j];
						index = j;
					}
				}
			}
		}
	}
	cout << alphabet[index] << "\n";
	
	return 0;
}

