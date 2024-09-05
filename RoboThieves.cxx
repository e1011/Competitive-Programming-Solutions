#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m, startx, starty;
	cin >> n >> m;
	
	vector <vector <int>> grid(n, vector <int> (m, 0));
	vector <vector <int>> cameras(0);
	vector <vector <int>> dp(n, vector <int> (m, -1));
	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j ++) {
			if (s[j] == 'W') {
				grid[i][j] = 1;
			}
			else if (s[j] == 'C') {
				cameras.push_back({i, j});
			}
			else if (s[j] == 'S') {
				startx = i;
				starty = j;
			}
			else if (s[j] == 'U') {
				grid[i][j] = 2;
			}
			else if (s[j] == 'R') {
				grid[i][j] = 3;
			}
			else if (s[j] == 'D') {
				grid[i][j] = 4;
			}
			else if (s[j] == 'L') {
				grid[i][j] = 5;
			}
		}
	}
	
	for (int i = 0; i < cameras.size(); i ++) {
		for (int j = cameras[i][1]; j < m; j ++) {
			if (grid[cameras[i][0]][j] == 0) {
				grid[cameras[i][0]][j] = -1;
			}
			else if (grid[cameras[i][0]][j] == 1) {
				break;
			}
		}
		for (int j = cameras[i][1]; j >= 0; j --) {
			if (grid[cameras[i][0]][j] == 0) {
				grid[cameras[i][0]][j] = -1;
			}
			else if (grid[cameras[i][0]][j] == 1) {
				break;
			}
		}
		for (int j = cameras[i][0]; j < n; j ++) {
			if (grid[j][cameras[i][1]] == 0) {
				grid[j][cameras[i][1]] = -1;
			}
			else if (grid[j][cameras[i][1]] == 1) {
				break;
			}
		}
		for (int j = cameras[i][0]; j >= 0; j --) {
			if (grid[j][cameras[i][1]] == 0) {
				grid[j][cameras[i][1]] = -1;
			}
			else if (grid[j][cameras[i][1]] == 1) {
				break;
			}
		}
	}
	
	queue <vector <int>> q;
	q.push({startx, starty, 0});
	while (q.empty() == false) {
		int x=q.front()[0], y=q.front()[1], steps=q.front()[2], dir=0;
		q.pop();
		if ((dp[x][y] == -1 || steps < dp[x][y]) && grid[x][y] != -1) {
			dp[x][y] = steps;
			if (grid[x][y] >= 2) {
				dir = grid[x][y];
			}
			
			if ((dir == 0 || dir == 2) && grid[x-1][y] != 1 && grid[x-1][y] != -1) {
				q.push({x-1, y, steps+(!dir)});
			}
			if ((dir == 0 || dir == 3) && grid[x][y+1] != 1 && grid[x][y+1] != -1) {
				q.push({x, y+1, steps+(!dir)});
			}
			if ((dir == 0 || dir == 4) && grid[x+1][y] != 1 && grid[x+1][y] != -1) {
				q.push({x+1, y, steps+(!dir)});
			}
			if ((dir == 0 || dir == 5) && grid[x][y-1] != 1 && grid[x][y-1] != -1) {
				q.push({x, y-1, steps+(!dir)});
			}		
		}
	}
	
	
	grid[startx][starty] = 10;
	for (int i = 0; i < cameras.size(); i ++) {
		grid[cameras[i][0]][cameras[i][1]] = 10;
	}
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (grid[i][j] == 0 || grid[i][j] == -1) {
				cout << dp[i][j] << "\n";
			}
		}
	}
	
	
	
	return 0;
}

