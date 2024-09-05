#include <iostream>
#include <vector>

using namespace std;

int main () {
	int t;
	cin >> t;
	
	for (int _ = 0; _ < t; _ ++) {
		int n;
		cin >> n;
		
		vector <long long int> dp(n, 0);
		dp[0] = 0;
		dp[1] = 1;
	 
		for (int i = 2; i < n; i++) {
			dp[i] = (i) * (dp[i - 1] + dp[i - 2]);
			dp[i] %= 1000000007;
		}
		
		cout << dp[n-1] << "\n";	
	}
	
	
	return 0;
}

