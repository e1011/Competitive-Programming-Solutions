#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool works = 1;
vector <int> arr(0), visited;
vector <vector <int>> graph;

void dfs(int node) {
	visited[node] = 1;
	for (int i = 0; i < graph[node].size(); i ++) {
		if (visited[graph[node][i]] == 0) {
			dfs(graph[node][i]);
		}
		else if (visited[graph[node][i]] == 1) {
			works = 0;
		}
	}
	visited[node] = 2;
	arr.push_back(node);
}

int main() {
	int n, m;
	cin >> n >> m;
	
	graph = vector <vector <int>> (n, vector <int> (0));
	visited = vector <int> (n, 0);
	for (int i = 0; i < m; i ++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
	}
	
	for (int i = 0; i < n; i ++) {
		if (visited[i] == 0) {
			dfs(i);
		}
	}
	reverse(arr.begin(), arr.end());
	
	if (works) {
		for (int i = 0; i < n; i ++) {
			cout << arr[i]+1 << "\n";
		}
	}
	else {
		cout << "IMPOSSIBLE\n";
	}
	
	
	return 0;
}

