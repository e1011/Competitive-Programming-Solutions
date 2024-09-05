#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, ans=0;
	string s;
	cin >> n >> s;
	
	for (int i = 1; i < n; i ++) {
		if (s[i] != s[i-1]) {
			ans += 1;
		}
	}
	
	
	if (s[0] != s[n-1]) {
		cout << n << "\n";
	}
	else if (ans == 0) {
		cout << 1 << "\n";
	}
	else {
		cout << ans << "\n";
	}
	
	return 0;
}

