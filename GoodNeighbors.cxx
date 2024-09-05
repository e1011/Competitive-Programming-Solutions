#include <iostream>
#include <vector>

using namespace std;

int main() {
	int r, c, ans=0;
	cin >> r >> c;
	
	vector <vector <int>> grid(r, vector <int> (c, 0));
	for (int i = 0; i < r; i ++) {
		for (int j = 0; j < c; j ++) {
			cin >> grid[i][j];
			if (i != 0 && j != 0 && grid[i-1][j-1] == grid[i][j]) {
				ans = max(ans, grid[i][j]);
			}
			if (i != 0 && grid[i-1][j] == grid[i][j]) {
				ans = max(ans, grid[i][j]);
			}
			if (j != 0 && grid[i][j-1] == grid[i][j]) {
				ans = max(ans, grid[i][j]);
			}
			if (i != 0 && j != c-1 && grid[i-1][j+1] == grid[i][j]) {
				ans = max(ans, grid[i][j]);
			}
		}
	}
	
	cout << ans << "\n";
	
	
	return 0;
}

