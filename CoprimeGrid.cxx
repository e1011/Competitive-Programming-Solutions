#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int main() {
	int t;
	cin >> t;
	
	for (int _ = 0; _ < t; _ ++) {
		int n, m;
		cin >> n >> m;
		vector <vector <int>> grid(n, vector <int> (m, 0));
		
		if (n == 1 || m == 1) {
			cout << "-1\n";
			continue;
		}
		
		else {
			bool k = 0;
			if (n % 2 != 0 && m % 2 != 0 && gcd(m+1, n*m) != 1) {
				cout << "-1\n";
				continue;
			}
			int counter = 1;
			
			for (int i = 0; i < m; i ++) {
				grid[0][i] = counter;
				counter += 1;
			}
			for (int i = 1; i < n; i ++) {
				grid[i][m-1] = counter;
				counter += 1;
			}
			
			for (int i = n-1; i > 0; i --) {
				if (i % 2 == (n-1) % 2) {
					for (int j = m-2; j >= 0; j --) {
						grid[i][j] = counter;
						counter += 1;
						if (k && grid[i][j] == n*m) {
							grid[i][j] -= 2;
						}
						else if (k && grid[i][j] == n*m-2) {
							grid[i][j] += 2;
						}
					}
				}
				else {
					for (int j = 0; j < m-1; j ++) {
						grid[i][j] = counter;
						counter += 1;
						if (k && grid[i][j] == n*m) {
							grid[i][j] -= 2;
						}
						else if (k && grid[i][j] == n*m-2) {
							grid[i][j] += 2;
						}
					}
				}
			}
		}
		
		
		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				cout << grid[i][j] << " ";
			}
			cout << "\n";
		}
	}
	
	return 0;
}

