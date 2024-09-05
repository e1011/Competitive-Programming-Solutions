#include <vector>
#include <iostream>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

vector <vector <int>> graph, costs;
vector <int> dp1, dp2, dp3;

void dfs1(int node, int parent) {
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent) {
			dfs1(graph[node][i], node);
			
			if (dp1[graph[node][i]]+costs[node][i] > dp1[node]) {
				dp2[node] = dp1[node];
				dp1[node] = dp1[graph[node][i]]+costs[node][i];
			}
			else if (dp1[graph[node][i]]+costs[node][i] > dp2[node]) {
				dp2[node] = dp1[graph[node][i]]+costs[node][i];
			}
		}
	}
}

void dfs2(int node, int parent) {
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent) {
			if (dp1[graph[node][i]]+costs[node][i] == dp1[node]) {
				dp3[graph[node][i]] = max(dp2[node], dp3[node])+costs[node][i];
			}
			else {
				dp3[graph[node][i]] = max(dp1[node], dp3[node])+costs[node][i];
			}
			
			dfs2(graph[node][i], node);
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	
	graph = vector <vector <int>> (n, vector <int> (0));
	costs = vector <vector <int>> (n, vector <int> (0));
	dp1 = vector <int> (n, 0);
	dp2 = vector <int> (n, 0);
	dp3 = vector <int> (n, 0);
	
	for (int i = 0; i < n-1; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a-1].push_back(b-1);
		costs[a-1].push_back(c);
		graph[b-1].push_back(a-1);
		costs[b-1].push_back(c);
	}
	
	dfs1(0, -1);
	dfs2(0, -1);
	
	for (int i = 0; i < q; i ++) {
		int x;
		cin >> x;
		cout << max(dp1[x-1], dp3[x-1]) << "\n";
	}
	
	return 0;
}


