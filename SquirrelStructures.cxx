#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> graph, dp1, dp2, storage1;
vector <int> visited;

void dfs(int node, int parent) {
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent) {
			dfs(graph[node][i], node);
			dp2[node].push_back(graph[node][i]);
			for (int j = 0; j < dp2[graph[node][i]].size(); j ++) {
				dp1[node].push_back(dp2[graph[node][i]][j]);
				dp1[dp2[graph[node][i]][j]].push_back(node);
			}
		}
	}
}

void dfs2(int node, int parent) {
	visited[node] = 1;
	for (int i = 0; i < dp1[node].size(); i ++) {
		if (dp1[node][i] != parent) {
			storage1.push_back({node, dp1[node][i]});
			dfs2(dp1[node][i], node);
		}
	}
}

int main() {
	int n;
	cin >> n;
	
	graph = vector <vector <int>> (n, vector <int> (0));
	dp1 = graph;
	dp2 = graph;
	for (int i = 0; i < n-1; i ++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	
	dfs(0, -1);
	
	visited = vector <int> (n, 0);
	vector <vector <vector <int>>> storage2(0);
	for (int i = 0; i < n; i ++) {
		if (visited[i] == 0) {
			storage1 = vector <vector <int>> (0);
			dfs2(i, -1);
			storage2.push_back(storage1);
		}
	}
	
	cout << storage2.size() << "\n";
	for (int i = 0; i < storage2.size(); i ++) {
		cout << storage2[i].size()+1 << "\n";
		for (int j = 0; j < storage2[i].size(); j ++) {
			cout << storage2[i][j][0]+1 << " " << storage2[i][j][1]+1 << "\n"; 
		}
	}
	
	return 0;
}

