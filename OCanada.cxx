#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, g, ans=0;
	cin >> n >> g;
	
	multiset <vector <vector <int>>> m;
	
	for (int i = 0; i < g; i ++) {
		vector <vector <int>> grid(n, vector <int> (n, 0));
		for (int j = 0; j < n; j ++) {
			string s;
			cin >> s;
			for (int k = 0; k < n; k ++) {
				if (s[k] == 'R') {
					grid[j][k] = 1;
				}
				else {
					grid[j][k] = 0;
				}
			}
		}
		
		for (int j = 0; j < n-1; j ++) {
			for (int k = 0; k < n-1; k ++) {
				if (grid[j][k] == 1) {
					grid[j][k] ^= 1;
					grid[j+1][k+1] ^= 1;
					grid[j+1][k] ^= 1;
					grid[j][k+1] ^= 1;
				}
			}
		}
		
		ans += m.count(grid);
		m.insert(grid);
	}
	
	cout << ans << "\n";
	
	return 0;
}

// how to find if two grids are similar?
// 0 1 1
// 0 1 1
// 0 1 1

// lexographically least. prioritize higher zeros, then leftmost zeros
// xor the entire grid until this happens
// 100*10000
