#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	freopen("snakes.in", "r" , stdin);
	freopen("snakes.out", "w" , stdout);
	
	int n, k;
	cin >> n >> k;
	
	vector <int> snakes(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> snakes[i];
	}
	
	vector <vector <int>> dp(k+2, vector <int> (n+1, 1000000000));
	dp[0][0] = 0;
	for (int i = 0; i < k+1; i ++) {
		for (int j = 0; j < n; j ++) {
			if (dp[i][j] != 1000000000) {
				int maximum=snakes[j], sum=0;
				dp[i+1][j+1] = min(dp[i+1][j+1], dp[i][j]);
				for (int l = j+1; l < n; l ++) {
					if (snakes[l] > maximum) {
						sum += (l-j)*(snakes[l]-maximum);
						maximum = snakes[l];
					}
					else if (snakes[l] < maximum) {
						sum += maximum-snakes[l];
					}
					dp[i+1][l+1] = min(dp[i+1][l+1], dp[i][j]+sum);
				}
			}
		}
	}
	
	cout << dp[k+1][n] << "\n";
	
	return 0;
}

