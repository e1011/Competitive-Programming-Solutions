#include <iostream>

using namespace std;

int main() {
	int n, counter=0, ans=0;
	string s;
	cin >> n >> s;
	
	if (n % 2 != 0) {
		cout << "-1\n";
		return 0;
	}
	
	for (int i = 0; i < n; i ++) {
		if (s[i] == '(') {
			counter += 1;
		}
		else {
			counter -= 1;
		}
		
		if (counter < 0) {
			ans += 1;
			counter += 2;
		}
		if (counter == n-i-1) {
			for (int j = i+1; j < n; j ++) {
				if (s[j] == '(') {
					ans += 1;
				}
			}
			break;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

