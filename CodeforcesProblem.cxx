#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, counter=0, ans=0;
	cin >> n;
	
	string s;
	cin >> s;
	
	for (int i = 0; i < n; i ++) {
		counter += (s[i] == 'Y');
		ans += (s[i] == 'Y');
	}
	
	for (int i = 0; i < counter; i ++) {
		if (s[i] == 'N') {
			counter += 1;
			ans += 1;
		}
	}
	
	if (ans*2 > n) {
		cout << "YES\n";
	}
	else {
		cout << "NO\n";
	}
	
	return 0;
}

