#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector <vector <int>> grid(n, vector <int> (n, 0));
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cin >> grid[i][j];
		}
		sort(grid[i].begin(), grid[i].end());
	}
	
	vector <int> medians(0);
	for (int i = 0; i < n; i ++) {
		medians.push_back(grid[i][n/2]);
	}
	sort(medians.begin(), medians.end());
	
	cout << medians[n/2] << "\n";
	
	return 0;
}

