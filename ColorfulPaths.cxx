#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m, a, b, c, d, works=0;
	cin >> n >> m;
	
	vector <vector <int>> graph(n, vector <int> (0));
	vector <vector <int>> edges(0);
	vector <vector <int>> dp(n, vector <int> (3, -1));
	for (int i = 0; i < m; i ++) {
		int a, b;
		cin >> a >> b;
		edges.push_back({a-1, b-1});
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	cin >> a >> b >> c >> d;
	
	// find path not passing through both c and d, from a to b
	queue <vector <int>> q;
	q.push({0, a-1, 0});
	while (q.empty() == false) {
		int dist = q.front()[0], node = q.front()[1], visited = q.front()[2];
		q.pop();
		
		if (visited == 0 && node == c-1) {
			visited = 1;
		}
		else if (visited == 0 && node == d-1) {
			visited = 2;
		}
		else if (visited > 0 && (node == c-1 || node == d-1)) {
			continue;
		}
		
		if (dp[node][visited] == -1) {
			dp[node][visited] = dist;
			for (int i = 0; i < graph[node].size(); i ++) {
				q.push({dist+1, graph[node][i], visited});
			}
		}
	}
	
	// output edge colorings
	if (dp[b-1][0] != -1 || dp[b-1][1] != -1 || dp[b-1][2] != -1) {
		works = 1;
	}
	for (int i = 0; i < m; i ++) {
		if (edges[i][0] == c-1 && edges[i][1] == d-1) {
			works = 0;
		}
		if (edges[i][0] == d-1 && edges[i][1] == c-1) {
			works = 0;
		}
	}
	
	if (works) {
		cout << "2\n";
		if (dp[b-1][2] == -1 || (dp[b-1][1] != -1 && dp[b-1][1] <= dp[b-1][2])) {
			for (int i = 0; i < m; i ++) {
				if (edges[i][0] == d-1 || edges[i][1] == d-1) {
					cout << "2\n";
				}
				else {
					cout << "1\n";
				}
			}
		}
		else {
			for (int i = 0; i < m; i ++) {
				if (edges[i][0] == c-1 || edges[i][1] == c-1) {
					cout << "2\n";
				}
				else {
					cout << "1\n";
				}
			}
		}
	}
	else {
		cout << "-1\n";
	}
	
	return 0;
}

