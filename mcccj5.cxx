#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, k, starti, startj;
	cin >> n >> k;
	
	vector <string> grid(n, "");
	for (int i = 0; i < n; i ++) {
		cin >> grid[i];
	}
	
	vector <vector <vector <int>>> dp(n, vector <vector <int>> (n, vector <int>(k, -1)));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (grid[i][j] == 'E') {
				starti = i;
				startj = j;
			}
		}
	}
	
	queue <vector <int>> q;
	q.push({starti, startj, 0});
	
	while (q.empty() == false) {
		int x = q.front()[0], y = q.front()[1], time = q.front()[2];
		q.pop();
		
		if (x >= 0 && x < n && y >= 0 && y < n && dp[x][y][time] == -1 && grid[x][y] != 'W') {
			cout << x << ", " << y << ", " << time << "\n";
			if (grid[x][y] == 'X') {
				cout << time << "\n";
				return 0;
			}
			dp[x][y][time] = 1;
			if ((time % k) == k-1) {
				int oldx = x;
				x = n-y-1;
				y = oldx;
			}
			if (grid[x][y] != 'W') {
				q.push({x-1, y, time+1});
				q.push({x+1, y, time+1});
				q.push({x, y+1, time+1});
				q.push({x, y-1, time+1});
			}
		}
	}
	
	cout << -1 << "\n";
	
	return 0;
}

