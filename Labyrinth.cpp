#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m;
	cin >> m >> n;
	
	vector <string> arr(n, "");
	vector <vector <int>> distances(n, vector <int> (m, 1000000000));
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
	}
	
	queue <vector <int>> q;
	q.push({0, 0, 0});
	while (!q.empty()) {
		int dist = q.front()[0], x = q.front()[1], y = q.front()[2];
		q.pop();
		if (x >= 0 && x < n && y >= 0 && y < m && dist < distances[x][y] && arr[x][y] == '.') {
			distances[x][y] = dist;
			q.push({dist+1, x-1, y});
			q.push({dist+1, x+1, y});
			q.push({dist+1, x, y+1});
			q.push({dist+1, x, y-1});
		}
	}
	
	cout << distances[n-1][m-1] << "\n";
	
	
	return 0;
}

