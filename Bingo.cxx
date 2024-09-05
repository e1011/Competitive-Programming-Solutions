#include <iostream>
#include <vector>
#include <set>

using namespace std;

int main() {
	int n, m;
	cin >> n;
	
	vector <string> arr(n, ""), ans(0);
	vector <vector <vector <int>>> grid(n, vector <vector <int>> (5, vector <int> (5, 0)));
	vector <vector <vector <int>>> grid2 = grid;
	
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		for (int j = 0; j < 5; j ++) {
			for (int k = 0; k < 5; k ++) {
				cin >> grid[i][j][k];
			}
		}
	}
	
	cin >> m;
	set <int> arr2;
	for (int i = 0; i < m; i ++) {
		int x;
		cin >> x;
		arr2.insert(x);
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < 5; j ++) {
			for (int k = 0; k < 5; k ++) {
				if (arr2.count(grid[i][j][k])) {
					grid2[i][j][k] = 1;
				}
			}
		}
	}
	
	for (int i = 0; i < n; i ++) {
		int total = 0;
		for (int j = 0; j < 5; j ++) {
			int counter = 0;
			for (int k = 0; k < 5; k ++) {
				if (grid2[i][j][k]) {
					counter += 1;
				}
			}
			total += (counter == 5);
		}
		for (int j = 0; j < 5; j ++) {
			int counter = 0;
			for (int k = 0; k < 5; k ++) {
				if (grid2[i][k][j]) {
					counter += 1;
				}
			}
			total += (counter == 5);
		}
		total += (grid2[i][0][0] && grid2[i][1][1] && grid2[i][2][2] && grid2[i][3][3] && grid2[i][4][4]);
		total += (grid2[i][0][4] && grid2[i][1][3] && grid2[i][2][2] && grid2[i][3][1] && grid2[i][4][0]);
		if (total) {
			ans.push_back(arr[i]);
		}
	}
	
	cout << ans.size() << "\n";
	for (int i = 0; i < ans.size(); i ++) {
		cout << ans[i] << "\n";
	}
	
	
	return 0;
}

