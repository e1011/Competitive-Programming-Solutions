#include <iostream>
#include <vector>

using namespace std;

int main() {
	string alphabet = "abcdefghijklmnopqrstuvwxyz";
	int t;
	cin >> t;
	for (int i = 0; i < t; i ++) {
		int n, current=0, second=0, ans=0;
		string s;
		cin >> n >> s;
		for (int j = 0; j < 26; j ++) {
			current = 0;
			second = 0;
			if (s[0] == alphabet[j]) {
				current = 1;
			}
			for (int k = 1; k < n; k ++) {
				//cout << current << ", " << second << ", " << ans << "\n";
				if (s[k] == alphabet[j]) {
					current += 1;
				}
				else {
					second = current;
					current = 0;
				}
				ans = max(ans, current+second+1);
			}
			ans = max(ans, current+second+1);
		}
		ans = min(n, ans);
		cout << ans << "\n";
	}
	
	return 0;
}

