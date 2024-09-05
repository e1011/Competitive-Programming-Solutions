#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int r, c, ans=0;
	cin >> r >> c;
	
	vector <vector <int>> grid(r, vector <int> (c, 0));
	for (int i = 0; i < r; i ++) {
		for (int j = 0; j < c; j ++) {
			cin >> grid[i][j];
		}
	}
	
	
	queue <vector <int>> q;
	for (int i = 0; i < r; i ++) {
		for (int j = 0; j < c; j ++) {
			if (grid[i][j] > 0) {
				ans += 1;
				q.push({i, j});
				while (q.empty() == false) {
					int x = q.front()[0], y = q.front()[1];
					q.pop();
					if (grid[x][y] != 0) {
						grid[x][y] = 0;
						if (x > 0) {
							q.push({x-1, y});
							if (y > 0) {
								q.push({x-1, y-1});
							}
							if (y < c-1) {
								q.push({x-1, y+1});
							}
						}
						
						if (x < r-1) {
							q.push({x+1, y});
							if (y > 0) {
								q.push({x+1, y-1});
							}
							if (y < c-1) {
								q.push({x+1, y+1});
							}
						}
						
						if (y > 0) {
							q.push({x, y-1});
						}
						if (y < c-1) {
							q.push({x, y+1});
						}
					}
				}
			}
		}
	}
	
	
	cout << ans << "\n";
	
	return 0;
}

