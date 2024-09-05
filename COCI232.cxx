#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, i1, j1, k1, i2, j2, k2;
	cin >> n >> i1 >> j1 >> k1 >> i2 >> j2 >> k2;
	
	vector <vector <vector <int>>> grid(n, vector <vector <int>> (n, vector <int> (n, -1)));
	vector <vector <vector <int>>> distances = grid;
	
	for (int k = 0; k < n; k ++) {
		for (int i = 0; i < n; i ++) {
			string s;
			cin >> s;
			for (int j = 0; j < n; j ++) {
				if (s[j] == '0') {
					grid[i][j][k] = 0;
				}
				else {
					grid[i][j][k] = 1;
				}
			}
		}
	}
	
	queue <vector <int>> q;
	q.push({0, i1-1, j1-1, k1-1});
	while (!q.empty()) {
		int dist = q.front()[0], i3 = q.front()[1], j3 = q.front()[2], k3 = q.front()[3];
		q.pop();
		
		if (min(i3, min(j3, k3)) >= 0 && max(i3, max(j3, k3)) < n && distances[i3][j3][k3] == -1 && grid[i3][j3][k3] == 0) {
			distances[i3][j3][k3] = dist;
			q.push({dist+1, i3-1, j3, k3});
			q.push({dist+1, i3+1, j3, k3});
			q.push({dist+1, i3, j3-1, k3});
			q.push({dist+1, i3, j3+1, k3});
			q.push({dist+1, i3, j3, k3-1});
			q.push({dist+1, i3, j3, k3+1});
		}
	}
	
	/*
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j ++) {
			for (int k = 0; k < n; k ++) {
				cout << distances[i][j][k] << " ";
			}
			cout << "\n";
		}
		cout << "\n\n";
	}
	* */
	
	cout << distances[i2-1][j2-1][k2-1] << "\n";
	
	return 0;
}

