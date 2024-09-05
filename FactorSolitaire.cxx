#include <iostream>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, ans=0;
	cin >> n;
	
	while (n > 1) {
		bool x = 0;
		for (int i = 2; i*i  <= n; i ++) {
			if (n % i == 0) {
				ans += (n-(n/i))/(n/i);
				n -= (n/i);
				x = 1;
				break;
			}
		}
		if (x == 0) {
			n -= 1;
			ans += n;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

