#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, ans=0;
	cin >> n;
	
	// maximum riceball from [i, j]
	vector <vector <int>> dp(n, vector <int> (n, -1));
	for (int i = 0; i < n; i ++) {
		cin >> dp[i][i];
		ans = max(ans, dp[i][i]);
	}
	
	for (int i = n-1; i >= 0; i --) {
		for (int j = i+1; j < n; j ++) {
			int pointer=j;
			for (int k = i; k < j; k ++) {
				if (dp[i][k] != -1) {
					if (dp[i][k] == dp[k+1][j]) {
						dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][j]);
					}
					while (pointer > i && (dp[i][k] > dp[pointer][j] || dp[pointer][j] == -1)) {
						pointer -= 1;
					}
					if (dp[i][k] == dp[pointer][j] && dp[k+1][pointer-1] != -1) {
						dp[i][j] = max(dp[i][j], dp[i][k]+dp[k+1][pointer-1]+dp[pointer][j]);
					}
				}
			}
			ans = max(ans, dp[i][j]);
		}
	}
	
	/*
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cout << dp[i][j] << " "; 
		}
		cout << "\n";
	}
	// 5 4 5 11 9 11 7 7
	*/
	
	cout << ans << "\n";
	
	return 0;
}

