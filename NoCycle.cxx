#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool possible = 1;
vector <vector <int>> graph(0);
vector <int> tsort, visited(0);

void dfs(int node, int parent) {
	visited[node] = 1;
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent) {
			if (visited[graph[node][i]] == 0) {
				dfs(graph[node][i], node);
			}
			else if (visited[graph[node][i]] == 1) {
				possible = 0;
			}
		}
	}
	tsort.push_back(node);
	visited[node] = 2;
}

int main() {
	int n, m, k;
	cin >> n >> m >> k;
	
	graph = vector <vector <int>> (n, vector <int> (0));
	tsort = vector <int> (n, 0);
	visited = vector <int> (n, 0);
	for (int i = 0; i < m; i ++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
	}
	
	for (int i = 0; i < n; i ++) {
		if (visited[i] == 0) {
			dfs(i, -1);
		}
	}
	reverse(tsort.begin(), tsort.end());
	vector <int> indexbynode(n, 0);
	for (int i = 0; i < n; i ++) {
		indexbynode[tsort[i]] = i;
	}
	
	
	if (possible == 1) {
		for (int i = 0; i < k; i ++) {
			int a, b;
			cin >> a >> b;
			
			if (indexbynode[a-1] > indexbynode[b-1]) {
				cout << b << " " << a << "\n";
			}
			else {
				cout << a << " " << b << "\n";
			}
		}
	}
	else {
		cout << -1 << "\n";
	}
	
	
	return 0;
}

