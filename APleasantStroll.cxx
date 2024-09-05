#include <iostream>
#include <vector>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	
	for (int _ = 0; _ < t; _ ++) {
		int n, m, ans=-1;
		cin >> n >> m;
		
		vector <vector <int>> grid(n+1, vector <int> (m, 0));
		for (int i = 0; i < n; i ++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j ++) {
				if (s[j] == '#') {
					grid[i][j] = 1;
				}
			}
		}
		
		vector <vector <vector <int>>> dp(n+1, vector <vector <int>> (m, vector <int> (m, -1)));
		for (int i = 0; i < m; i ++) { 
			for (int j = 0; j < m; j ++) {
				if (i != j && grid[0][i] == 0 && grid[0][j] == 0) {
					dp[0][i][j] = 0;
				}
			}
		}
		
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				for (int k = 0; k < m; k ++) {
					if (dp[i][j][k] == -1) {
						continue;
					}
					
					if (j == k-1 || j == k+1) {
						dp[i][j][k] += 1;
					}
					
					if (j != 0 && grid[i+1][j-1] == 0) {
						if (k != 0 && k-1 != j-1 && grid[i+1][k-1] == 0) {
							dp[i+1][j-1][k-1] = max(dp[i+1][j-1][k-1], dp[i][j][k]);
						}
						if (k != j-1 && grid[i+1][k] == 0) {
							dp[i+1][j-1][k] = max(dp[i+1][j-1][k], dp[i][j][k]);
						}
						if (k < m-1 && k+1 != j-1 && grid[i+1][k+1] == 0) {
							dp[i+1][j-1][k+1] = max(dp[i+1][j-1][k+1], dp[i][j][k]);
						}
					}
					if (grid[i+1][j] == 0){
						if (k != 0 && k-1 != j && grid[i+1][k-1] == 0) {
							dp[i+1][j][k-1] = max(dp[i+1][j][k-1], dp[i][j][k]);
						}
						if (k != j && grid[i+1][k] == 0) {
							dp[i+1][j][k] = max(dp[i+1][j][k], dp[i][j][k]);
						}
						if (k < m-1 && k+1 != j && grid[i+1][k+1] == 0) {
							dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k]);
						}
					}
					if (j < m-1 && grid[i+1][j+1] == 0) {
						if (k != 0 && k-1 != j+1 && grid[i+1][k-1] == 0) {
							dp[i+1][j+1][k-1] = max(dp[i+1][j+1][k-1], dp[i][j][k]);
						}
						if (k != j+1 && grid[i+1][k] == 0){
							dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k]);
						}
						if (k < m-1 && k+1 != j+1 && grid[i+1][k+1] == 0) {
							dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1], dp[i][j][k]);
						}
					}
				}
			}
		}
		
		for (int i = 0; i < m; i ++) {
			for (int j = 0; j < m; j ++) {
				ans = max(ans, dp[n][i][j]);
			}
		}
		
		if (ans == -1) {
			cout << "Detour\n";
		}
		else {
			cout << ans << "\n";
		}
	}
	
	
	
	return 0;
}

