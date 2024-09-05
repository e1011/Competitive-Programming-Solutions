#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	freopen("visitfj.in", "r", stdin);
	freopen("visitfj.out", "w", stdout);
	
	int n, t;
	cin >> n >> t;
	
	vector <vector <int>> field(n, vector <int> (n, 0));
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			cin >> field[i][j];
		}
	}
	
	vector <vector <vector <int>>> dp(n, vector <vector <int>> (n, vector <int> (3, -1)));
	priority_queue <vector <int>, vector <vector <int>>, greater <vector <int>>> pq;
	pq.push({0, 0, 0, 0});
	while (pq.empty() == false) {
		int dist=pq.top()[0], x=pq.top()[1], y=pq.top()[2], id=pq.top()[3];
		pq.pop();
		if (dp[x][y][id] == -1) {
			dp[x][y][id] = dist;
			if (id == 2) {
				if (x < n-1) {
					pq.push({dist+t+field[x+1][y], x+1, y, 0});
				}				
				if (x > 0) {
					pq.push({dist+t+field[x-1][y], x-1, y, 0});
				}
				if (y < n-1) {
					pq.push({dist+t+field[x][y+1], x, y+1, 0});
				}
				if (y > 0) {
					pq.push({dist+t+field[x][y-1], x, y-1, 0});
				}
			}
			else {
				if (x < n-1) {
					pq.push({dist+t, x+1, y, id+1});
				}				
				if (x > 0) {
					pq.push({dist+t, x-1, y, id+1});
				}
				if (y < n-1) {
					pq.push({dist+t, x, y+1, id+1});
				}
				if (y > 0) {
					pq.push({dist+t, x, y-1, id+1});
				}
			}
		}
	}
	
	cout << min(dp[n-1][n-1][0], min(dp[n-1][n-1][1], dp[n-1][n-1][2])) << "\n";
	
	return 0;
}

