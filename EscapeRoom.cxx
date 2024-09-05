#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	
	vector <vector <int>> grid(vector <vector <int>> (n, vector <int> (m, 0)));
	vector <vector <int>> dp(vector <vector <int>> (n, vector <int> (m, 0)));
	vector <vector <vector <int>>> factors(vector <vector <vector <int>>> (1000001, vector <vector <int>> (0)));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cin >> grid[i][j];
			if (factors[grid[i][j]].size() == 0) {
				for (int k = 1; k*k <= grid[i][j]; k ++) {
					if (grid[i][j] % k == 0) {
						if (k-1 < n && grid[i][j]/k-1 < m) {
							factors[grid[i][j]].push_back({k-1, grid[i][j]/k-1});
						}
						if (grid[i][j]/k-1 < n && k-1 < n) {
							factors[grid[i][j]].push_back({grid[i][j]/k-1, k-1});
						}
					}
				}
			}
		}
	}
	
	queue <vector <int>> q;
	q.push({0, 0});
	while (q.empty() == false) {
		int x=q.front()[0], y=q.front()[1];
		q.pop();
		
		if (dp[x][y] == 0) {
			dp[x][y] = 1;
			for (int i = 0; i < factors[grid[x][y]].size(); i ++) {
				if (dp[factors[grid[x][y]][i][0]][factors[grid[x][y]][i][1]] == 0) {
					q.push({factors[grid[x][y]][i][0], factors[grid[x][y]][i][1]});
				}
			}
		}
	}
	
	if (dp[n-1][m-1] == 1) {
		cout << "yes\n";
	}
	else {
		cout << "no\n";
	}
	
	return 0;
}

