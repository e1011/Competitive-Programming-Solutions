#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, ans=0;
	
	cin >> n;
	vector <int> pies(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> pies[i];
	}
	
	cin >> m;
	vector <int> bucket(m, 0);
	for (int i = 0; i < m; i ++) {
		cin >> bucket[i];
	}
	sort(bucket.begin(), bucket.end());
	reverse(bucket.begin(), bucket.end());
	
	vector <vector <vector <int>>> dp(n+1, vector <vector <int>> (m+1, vector <int> (m+1, 0)));
	for (int i = 0; i < n+1; i ++) {
		for (int j = 0; j < m+1; j ++) {
			for (int k = 0; k < m+1; k ++) {
				bool works = 0;
				
				if (i+2 < n+1) {
					works = 1;
					dp[i+2][j][k] = max(dp[i+2][j][k], dp[i][j][k]+pies[i]);
				}
				if (i+1 < n+1 && j+k+1 < m+1) {
					works = 1;
					dp[i+1][j][k+1] = max(dp[i+1][j][k+1], dp[i][j][k]+pies[i]);
				}
				
				if (i+3 < n+1) {
					works = 1;
					dp[i+3][j][k] = max(dp[i+3][j][k], dp[i][j][k]+pies[i]);
				}
				if (i+2 < n+1 && j+k+1 < m+1) {
					works = 1;
					dp[i+2][j][k+1] = max(dp[i+2][j][k+1], dp[i][j][k]+pies[i]); 
				}
				if (i+1 < n+1 && j+k+2 < m+1) {
					works = 1;
					dp[i+1][j][k+2] = max(dp[i+1][j][k+2], dp[i][j][k]+pies[i]); 
				}
				
				if (i+1 < n+1 && j+k+1 < m+1) {
					works = 1;
					dp[i+1][j+1][k] = max(dp[i+1][j+1][k], dp[i][j][k]+bucket[j]);
				}
				if (j+k+2 < m+1) {
					works = 1;
					dp[i][j+1][k+1] = max(dp[i][j+1][k+1], dp[i][j][k]+bucket[j]);
				}
				
				if (i+2 < n+1 && j+k+1 < m+1) {
					works = 1;
					dp[i+2][j+1][k] = max(dp[i+2][j+1][k], dp[i][j][k]+bucket[j]);
				}
				if (i+1 < n+1 && j+k+2 < m+1) {
					works = 1;
					dp[i+1][j+1][k+1] = max(dp[i+1][j+1][k+1], dp[i][j][k]+bucket[j]);
				}
				if (j+k+3 < m+1) {
					works = 1;
					dp[i][j+1][k+2] = max(dp[i][j+1][k+2], dp[i][j][k]+bucket[j]);
				}
				
				
				if (works == 0 && j+k+1 < m+1) {
					dp[i][j][k] = max(dp[i][j][k], dp[i][j][k]+bucket[j]);
				}
				else if (works == 0 && i+1 < n+1) {
					dp[i][j][k] = max(dp[i][j][k], dp[i][j][k]+pies[i]);
				}
				
 				ans = max(ans, dp[i][j][k]);
			}
		}
	}
	
	/*
	for (int i = 0; i < n+1; i ++) {
		for (int j = 0; j < m+1; j ++) {
			for (int k = 0; k < m+1; k ++) {
				cout << dp[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n\n";
	}
	* */
	
	cout << ans << "\n";
	
	return 0;
}

