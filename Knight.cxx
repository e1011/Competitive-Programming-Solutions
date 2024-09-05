#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector <vector <int>> distances(n, vector <int> (m, 1000000000));
	vector <vector <int>> dp(n, vector <int> (m, 0));
	vector <vector <int>> grid(n, vector <int> (m, 0));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cin >> grid[i][j];
		}
	}
	
	queue <vector <int>> q;
	q.push({0, 0, 0, 0, 0});
	dp[0][0] = 1;
	while (q.empty() == false) {
		int dist = q.front()[0], x = q.front()[1], y = q.front()[2], pastx = q.front()[3], pasty = q.front()[4];
		q.pop();
		if (x >= 0 && x < n && y >= 0 && y < m && distances[x][y] >= dist && grid[x][y] == 0) {
			if (distances[x][y] == dist) {
				dp[x][y] += dp[pastx][pasty];
				dp[x][y] %= 1000000;
			}
			else {
				distances[x][y] = dist;
				dp[x][y] = dp[pastx][pasty];
				q.push({dist+1, x+1, y, x, y});
				q.push({dist+1, x-1, y, x, y});
				q.push({dist+1, x, y+1, x, y});
				q.push({dist+1, x, y-1, x, y});
			}
		}
	}
	
	
	cout << dp[n-1][m-1] << "\n";
}

