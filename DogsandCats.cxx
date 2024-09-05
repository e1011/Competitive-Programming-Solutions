#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector <long long> dp(n, 1);
	vector <long long> dp2(n, 0);
	dp2[0] = 1;
	for (int i = 1; i < n; i ++) {
		if (i > k) {
			dp[i] += dp2[i-k-1];
			dp[i] %= 1000000007;
		}
		dp2[i] = dp[i] + dp2[i-1];
		dp2[i] %= 1000000007;
	}
	
	cout << (long long)(dp2[n-2] + dp[n-1] + 1) % 1000000007 << "\n";
	
	return 0;
}

