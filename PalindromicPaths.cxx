#include <iostream>
#include <vector>

using namespace std;

int main() {
	freopen("palpath.in", "r", stdin);
	freopen("palpath.out", "w", stdout);
	int n, ans=0;
	cin >> n;
	
	vector <string> grid(n, "");
	// i1, j1, i2, (i1+j1-i2)
	vector <vector <vector <int>>> dp(n, vector <vector <int>> (n, vector <int> (n, 0)));
	for (int i = 0; i < n; i ++) {
		cin >> grid[i];
	}
	if (grid[0][0] == grid[n-1][n-1]) {
		dp[0][0][0] = 1;
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			for (int k = 0; k < n; k ++) {
				if (grid[i][j] == grid[n-1-k][n-1-(i+j-k)]) {
					if (j != 0) {
						dp[i][j][k] += dp[i][j-1][k];
						dp[i][j][k] %= 1000000007;
					}
					if (i != 0) {
						dp[i][j][k] += dp[i-1][j][k];
						dp[i][j][k] %= 1000000007;
					}
					if (j != 0 && k != 0) {
						dp[i][j][k] += dp[i][j-1][k-1];
						dp[i][j][k] %= 1000000007;
					}
					if (i != 0 && k != 0) {
						dp[i][j][k] += dp[i-1][j][k-1];
						dp[i][j][k] %= 1000000007;
					}
					dp[i][j][k] %= 1000000007;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i ++) {
		ans += dp[i][n-1-i][n-1-i];
		ans %= 1000000007;
	}
	
	cout << ans << "\n";
	
	return 0;
}

