#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, ans = 101;
	cin >> n;
	
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		ans = min(ans, x);
	}
	
	cout << ans << "\n";
	
	return 0;
}

