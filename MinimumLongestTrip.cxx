#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// bestcandidate refers index in order of edges, not the node
vector <int> visited, tsort(0), maxlen, bestcandidate;
vector <long long> labelsum;
vector <vector <int>> graph, labels;

void dfs(int node) {
	for (int i = 0; i < graph[node].size(); i ++) {
		if (visited[graph[node][i]] == 0) {
			visited[graph[node][i]] = 1;
			dfs(graph[node][i]);
		}
	}
	tsort.push_back(node);
}

vector <int> getbest(vector <int> candidates) {
	
}

int main() {
	int n, m;
	cin >> n >> m;
	
	visited = vector <int> (n, 0);
	maxlen = visited;
	bestcandidate = visited;
	labelsum = vector <long long> (n, 0);
	
	graph = vector <vector <int>> (n, vector <int> (0));
	labels = graph;
	
	for (int i = 0; i < m; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a-1].push_back(b-1);
		labels[a-1].push_back(c);
	}
	
	for (int i = 0; i < n; i ++) {
		if (visited[i] == 0) {
			visited[i] = 1;
			dfs(i);
		}
	}
	reverse(tsort.begin(), tsort.end());
	
	for (int i = n-1; i >= 0; i --) {
		vector <vector <long long>> candidates(0);
		for (int j = 0; j < graph[tsort[i]].size(); j ++) {
			candidates.push_back({-maxlen[graph[tsort[i]][j]]-1, labels[tsort[i]][j], labelsum[graph[tsort[i]][j]]+labels[tsort[i]][j]});
		}
		sort(candidates.begin(), candidates.end());
		
		if (candidates.size() > 0) {
			maxlen[tsort[i]] = -candidates[0][0];
			labelsum[tsort[i]] = candidates[0][2];
			bestcandidate[tsort[i]] = j;
		}
	}
	
	for (int i = 0; i < n; i ++) {
		cout << maxlen[i] << " " << labelsum[i] << "\n";
	}
	
	return 0;
}

