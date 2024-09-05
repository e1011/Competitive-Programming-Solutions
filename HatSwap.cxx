#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m, ans=1000000000;
	cin >> n >> m;
	
	vector <int> colors(n, 0);
	vector <int> seen1(n, 0);
	vector <int> seen2(n, 0);
	vector <vector <int>> graph(n, vector <int> (0));
	vector <vector <vector <int>>> seencolors(n, vector <vector <int>> (0));
	
	for (int i = 0; i < n; i ++) {
		cin >> colors[i];
		colors[i] -= 1;
	}
	for (int i = 0; i < m; i ++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	
	queue <vector <int>> q;
	q.push({0, 0});
	while (q.empty() == false) {
		int dist = q.front()[0], node = q.front()[1];
		q.pop();
		if (seen1[node] == 0) {
			seen1[node] = 1;
			seencolors[colors[node]].push_back({dist, node});
			for (int i = 0; i < graph[node].size(); i ++) {
				q.push({dist+1, graph[node][i]});
			}
		}
	}
	
	q.push({0, n-1});
	while (q.empty() == false) {		
		int dist = q.front()[0], node = q.front()[1];
		q.pop();
		if (seen2[node] == 0) {
			seen2[node] = 1;
			for (int i = 0; i < min(2, (int)seencolors[colors[node]].size()); i ++) {
				if (seencolors[colors[node]][i][1] != node) {
					ans = min(ans, dist+seencolors[colors[node]][i][0]);
				}
			}
			for (int i = 0; i < graph[node].size(); i ++) {
				q.push({dist+1, graph[node][i]});
			}
		}
	}
	
	if (ans == 1000000000) {
		cout << "-1\n";
	}
	else {
		cout << ans << "\n";
	}
	
	return 0;
}

