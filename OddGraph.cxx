#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool possible = 1;
map <vector <int>, vector <int>> edgetoindex;
vector <vector <int>> graph;
vector <int> visited, dp;

void dfs(int node, int parent) {
	visited[node] = 1;
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent && visited[graph[node][i]] == 0) {
			dfs(graph[node][i], node);
			if (dp[graph[node][i]] % 2 != 0) {
				edgetoindex[{min(node, graph[node][i]), max(node, graph[node][i])}][1] = 1;
				dp[node] += dp[graph[node][i]];
			}
		}
	}
	if (parent == -1 && dp[node] % 2 == 1) {
		possible = 0;
	}
	return;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	graph = vector <vector <int>> (n, vector <int> (0));
	visited = vector <int> (n, 0);
	dp = vector <int> (n, 1);
	for (int i = 0; i < m; i ++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
		edgetoindex[{min(a-1, b-1), max(a-1, b-1)}] = {i+1, 0};
	}
	
	for (int i = 0; i < n; i ++) {
		if (visited[i] == 0) {
			dfs(i, -1);
		}
	}
	
	vector <int> ans(0);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < graph[i].size(); j ++) {
			if (i < graph[i][j] && edgetoindex[{i, graph[i][j]}][1] == 1) {
				ans.push_back(edgetoindex[{i, graph[i][j]}][0]);
			}
		}
	}
	
	if (possible) {
		cout << ans.size() << "\n";
		for (int i = 0; i < ans.size(); i ++) {
			cout << ans[i] << "\n";
		}
	}
	else {
		cout << "-1\n";
	}
	
	return 0;
}

// bug somewhere
