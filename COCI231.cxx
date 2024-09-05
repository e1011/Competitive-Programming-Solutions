#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, ans=0;
	cin >> n >> m;
	
	vector <string> grid(n, "");
	for (int i = 0; i < n; i ++) {
		cin >> grid[i];
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (grid[i][j] == '+') {
				int works = 1;
				for (int k = 1; k < n; k ++) {
					if (i-k < 0 || grid[i-k][j] != '|') {
						works = 0;
					}
					if (j-k < 0 || grid[i][j-k] != '-') {
						works = 0;
					}
					if (i-k < 0 || j-k < 0 || grid[i-k][j-k] != '\\') {
						works = 0;
					}
					if (i+k >= n || grid[i+k][j] != '|') {
						works = 0;
					}
					if (j+k >= m || grid[i][j+k] != '-') {
						works = 0;
					}
					if (i+k >= n || j+k >= m || grid[i+k][j+k] != '\\') {
						works = 0;
					}
					if (i-k < 0 || j+k >= m || grid[i-k][j+k] != '/') {
						works = 0;
					}
					if (i+k >= n || j-k < 0 || grid[i+k][j-k] != '/') {
						works = 0;
					}
					if (works == 0) {
						ans = max(ans, k-1);
						break;
					}
				}
				//cout << i << ", " << j << ", " << ans << "\n";
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

