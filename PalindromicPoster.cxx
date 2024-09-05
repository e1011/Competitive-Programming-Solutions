#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, r, c;
	cin >> n >> m >> r >> c;
	
	vector <vector <char>> ans(n, vector <char> (m, 'c'));
	if (r == n) {
		int edgefill = c/2, centrefill=0;
		if (m % 2 == 1) {
			if (c % 2 == 1) {
				centrefill = 1;
			}
		}
		else {
			if (c % 2 == 1) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
		}
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				ans[i][j] = 'b';
			}
		}
		for (int i = 0; i < m; i ++) {
			ans[0][i] = 'a';
		}
		for (int i = 0; i < m; i ++) {
			if (i < edgefill || i+edgefill >= m) {
				ans[0][i] = 'b';
			}
			if (i == m/2 && centrefill) {
				ans[0][i] = 'b';
			} 
		}
	}
	else if (c == m) {
		int edgefill = r/2, centrefill=0;
		if (n % 2 == 1) {
			if (r % 2 == 1) {
				centrefill = 1;
			}
		}
		else {
			if (r % 2 == 1) {
				cout << "IMPOSSIBLE\n";
				return 0;
			}
		}
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				ans[i][j] = 'b';
			}
		}
		for (int i = 0; i < n; i ++) {
			ans[i][0] = 'a';
		}
		for (int i = 0; i < n; i ++) {
			if (i < edgefill || i+edgefill >= n) {
				ans[i][0] = 'b';
			}
			if (i == n/2 && centrefill) {
				ans[i][0] = 'b';
			} 
		}
	}
	else {
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (i < r || j < c) {
					ans[i][j] = 'a';
				}
			}
		}
	}
	
	// fill everything else
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			if (ans[i][j] != 'a' && ans[i][j] != 'b') {
				if ((i+j) % 3 == 0) {
					ans[i][j] = 'x';
				}
				else if ((i+j) % 3 == 1) {
					ans[i][j] = 'y';
				}
				else {
					ans[i][j] = 'z';
				}
			}
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < m; j ++) {
			cout << ans[i][j];
		}
		cout << "\n";
	}
	
	
	return 0;
}

