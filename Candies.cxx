#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	vector <int> arr(n, 0);
	
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	
	vector <vector <int>> dp(n+1, vector <int> (k+1, 0));
	dp[0][0] = 1;
	for (int i = 0; i < n; i ++) {
		int sum = 0;
		for (int j = 0; j < k+1; j ++) {
			sum += dp[i][j];
			sum %= 1000000007;
			if (j > arr[i]) {
				sum -= dp[i][j-arr[i]-1];
				sum += 1000000007;
				sum %= 1000000007;
			}
			dp[i+1][j] = sum;
		}
	}
	
	cout << dp[n][k] << "\n";
	
	return 0;
}

