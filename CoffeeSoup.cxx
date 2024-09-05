#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, k, ans;
	cin >> n >> m >> k;
	
	vector <vector <int>> dp(400, vector <int> (400, 1000));
	vector <vector <int>> coffees(n, vector <int> (2, 0));
	
	for (int i = 0; i < n; i ++) {
		cin >> coffees[i][0] >> coffees[i][1];
	}
	
	dp[0][0] = 0;
	for (int i = 0; i < 301; i ++) {
		for (int j = 0; j < 301; j ++) {
			for (int l = 0; l < n; l ++) {
				dp[i+coffees[l][0]][j+coffees[l][1]] = min(dp[i+coffees[l][0]][j+coffees[l][1]], dp[i][j]+1);
			}
		}
	}
	
	for (int i = 0; i*m < 351; i ++) {
		if (dp[i][m*i] <= k) {
			ans = i;
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

