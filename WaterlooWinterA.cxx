#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int _ = 0; _ < t; _ ++) {
		int n, counter=0;
		cin >> n;
		
		vector <vector <int>> grid(n, vector <int> (n, 0));
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < n; j ++) {
				cin >> grid[i][j];
			}
		}
		
		vector <int> arr(0);
		for (int i = 0; i < n; i ++) {
			if (i % 2 == 0) {
				for (int j = 0; j < n; j ++) {
					arr.push_back(grid[i][j]);
				}
			}
			else {
				for (int j = n-1; j >= 0; j --) {
					arr.push_back(grid[i][j]);
				}
			}
		}
		
		for (int i = 1; i < n*n; i ++) {
			if (arr[i] > arr[i-1]) {
				counter -= 1;
			}
			else {
				counter += 1;
			}
		}
		if (counter < 0) {
			reverse(arr.begin(), arr.end());
		}
		
		for (int i = 0; i < n*n; i ++) {
			cout << arr[i];
			if (i == n*n-1) {
				cout << "\n";
			}
			else {
				cout << " ";
			}
		}
		
	}
	
	
	return 0;
}

