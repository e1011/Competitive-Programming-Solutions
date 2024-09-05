#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector <vector <int>> grid(n, vector <int> (m, 0));
	
	for (int i = 0; i < n; i ++) {
		string s;
		cin >> s;
		for (int j = 0; j < m; j ++) {
			if (s[j] == 'W') {
				grid[i][j] = 1;
			}
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (grid[i][j] == 1) {
				cout << 'W';
			}
			else if (i > 0 && grid[i-1][j] == 1) {
				cout << "C";
			}
			else if (i < n-1 && grid[i+1][j] == 1) {
				cout << "C";
			}
			else if (j > 0 && grid[i][j-1] == 1) {
				cout << "C";
			}
			else if (j < m-1 && grid[i][j+1] == 1) {
				cout << "C";
			}
			else {
				cout << ".";
			}
		}
		cout << "\n";
	}
	
	
	return 0;
}

