#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, _;
	cin >> n >> m >> _;
	
	vector <vector <int>> dp(n+1, vector <int> (m+1, -1));
	vector <int> happiness(m, 0);
	vector <int> amount(m, 0);
	for (int i = 0; i < m; i ++) {
		cin >> happiness[i] >> amount[i];
	}
	
	dp[0][0] = 0;
	for (int i = 0; i < n+1; i ++) {
		for (int j = 0; j < m; j ++) {
			if (dp[i][j] != -1) {
				int sum = 0;
				for (int k = 0; k <= amount[j]; k ++) {
					if (k > 0) {
						sum += happiness[j]/k;
					}
					if (i+k < n+1) {
						dp[i+k][j+1] = max(dp[i+k][j+1], dp[i][j]+sum);
					}
				}
			}
		}
	}
	
	cout << dp[n][m] << "\n";
	
	return 0;
}

