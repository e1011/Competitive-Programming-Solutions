#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> graph;
vector <int> dp, active;

void dfs1(int node, int parent) {
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent && active[graph[node][i]]) {
			dfs1(graph[node][i], node);
			dp[node] += dp[graph[node][i]];
		}
	}
}

int dfs2(int node, int parent, int total) {
	int maxval=0, maxnode;
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent && active[graph[node][i]]) {
			if (dp[graph[node][i]] > maxval) {
				maxnode = graph[node][i];
				maxval = dp[graph[node][i]];
			}
		}
	}
	
	if (maxval*2 > total) {
		return dfs2(maxnode, node, total);
	}
	else {
		return node;
	}
}

bool dfs3(int node, int parent, int target) {
	if (node == target) {
		return true;
	}
	bool works = 0;
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent && active[graph[node][i]]) {
			works = max(works, dfs3(graph[node][i], node, target));
		}
	}
	return works;
}

int main() {
	int n, newstart=0;
	cin >> n;
	
	active = vector <int> (n, 1);
	graph = vector <vector <int>> (n, vector <int> (0));
	
	for (int i = 0; i < n-1; i ++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	
	while (true) {
		dp = vector <int> (n, 1);
		dfs1(newstart, -1);
		
		int center = dfs2(newstart, -1, dp[newstart]), result;
		active[center] = 0;
		cout << center+1 << "\n";
		cin >> result;
		result -= 1;
		
		if (result == -1) {
			return 0;
		}
		else if (result == -2) {
			return 0;
		}
		
		for (int i = 0; i < graph[center].size(); i ++) {
			if (dfs3(graph[center][i], -1, result)) {
				newstart = graph[center][i];
				break;
			}
		}
	}
	
	return 0;
}

