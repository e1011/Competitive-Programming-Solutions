#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> graph;
vector <int> vis;
vector <int> tsort(0);
bool works = 1;

void dfs(int node) {
	vis[node] = 1;
	for (int i = 0; i < graph[node].size(); i ++) {
		if (vis[graph[node][i]] == 0) {
			dfs(graph[node][i]);
		}
		else if (vis[graph[node][i]] == 1) {
			works = false;
		}
	}
	vis[node] = 2;
	tsort.push_back(node);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m;
	cin >> n >> m;
	
	graph = vector <vector <int>> (n, vector <int> (0));
	vis = vector <int> (n, 0);
	
	for (int i = 0; i < m; i ++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
	}
	
	for (int i = 0; i < n; i ++) {
		if (vis[i] == 0) {
			dfs(i);
		}
	}
	
	if (works == 0) {
		cout << "-1\n";
	}
	else {
		cout << n << "\n";
		for (int i = 0; i < n; i ++) {
			cout << tsort[i]+1 << " " << 1 << "\n";
		}
	}
	
	
	return 0;
}

