#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m, ans=0;
	cin >> n >> m;
	
	vector <vector <int>> grid(n, vector <int> (m, 0));
	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j ++) {
			if (s[j] == 'W') {
				grid[i][j] = 0;
			}
			if (s[j] == 'L') {
				grid[i][j] = 1;
			}
			if (s[j] == 'C') {
				grid[i][j] = 2;
			}
		}
	}
	
	queue <vector <int>> q;
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (grid[i][j] == 1) {
				q.push({i, j});
				ans += 1;
				
				while (q.empty() == false) {
					int qi = q.front()[0], qj = q.front()[1];
					q.pop();
					if (qi >= 0 && qi < n && qj >= 0 && qj < m && grid[qi][qj] == 1) {
						grid[qi][qj] = 3;
						q.push({qi-1, qj});
						q.push({qi+1, qj});
						q.push({qi, qj-1});
						q.push({qi, qj+1});
					}
				}
			}
			
			if (grid[i][j] == 3) {
				if (i != 0 && grid[i-1][j] == 2) {
					grid[i-1][j] = 4;
				}
				if (i < n-1 && grid[i+1][j] == 2) {
					grid[i+1][j] = 4;
				}
				if (j != 0 && grid[i][j-1] == 2) {
					grid[i][j-1] = 4;
				}
				if (j < m-1 && grid[i][j+1] == 2) {
					grid[i][j+1] = 4;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			int evens=0, odds=0;
			if (grid[i][j] == 2) {
				q.push({i, j});
				while (q.empty() == false) {
					int qi = q.front()[0], qj = q.front()[1];
					q.pop();
					if (qi >= 0 && qi < n && qj >= 0 && qj < m && grid[qi][qj] == 2) {
						grid[qi][qj] = 5;
						if ((qi+qj) % 2 == 0) {
							evens += 1;
						}
						else {
							odds += 1;
						}
						
						q.push({qi-1, qj});
						q.push({qi+1, qj});
						q.push({qi, qj-1});
						q.push({qi, qj+1});
					}
				}
			}
			ans += max(evens, odds);
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cout << grid[i][j] << " ";
		}
		cout << "\n";
	}
	
	cout << ans << "\n";
	
	return 0;
}

