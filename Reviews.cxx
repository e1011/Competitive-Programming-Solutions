#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int>> graph;
// dp1 is distance traveled to all targets in subtree and then back
// dp2 is distance traveled to all outside subtree then back
// dp3 is max dist to any target in subtree, not back
// dp4 is second largest dist to any target in subtree
// dp5 is max dist to any target not in subtree
vector <int> targets, dp1, dp2, dp3, dp4, dp5;

void dfs1(int node, int parent) {
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent) {
			dfs1(graph[node][i], node);
			if (targets[graph[node][i]] || dp1[graph[node][i]]) {
				dp1[node] += dp1[graph[node][i]]+2;
				if (dp3[graph[node][i]]+1 > dp3[node]) {
					dp4[node] = dp3[node];
					dp3[node] = dp3[graph[node][i]]+1;
				}
				else if (dp3[graph[node][i]]+1 > dp4[node]) {
					dp4[node] = dp4[graph[node][i]];
				}
				if (dp4[graph[node][i]]+1 > dp4[node]) {
					dp4[node] = dp4[graph[node][i]];
				}
			}
		}
	}
}

void dfs2(int node, int parent) {
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent) {
			dp2[graph[node][i]] = dp2[node]+dp1[node]-dp1[graph[node][i]];
			if (dp3[graph[node][i]]+1 == dp3[node]) {
				dp5[graph[node][i]] = dp4[node]+1;
			}
			else {
				dp5[graph[node][i]] = dp3[node]+1;
			}
			dp5[graph[node][i]] = max(dp5[graph[node][i]], dp5[node]+1);
			dfs2(graph[node][i], node);
		}
	}
}

int main() {
	int n, m, ans=1000000000;
	cin >> n >> m;
	
	graph = vector <vector <int>> (n, vector <int> (0));
	targets = vector <int> (n, 0);
	dp1 = vector <int> (n, 0);
	dp2 = vector <int> (n, 0);
	dp3 = vector <int> (n, 0);
	dp4 = vector <int> (n, 0);
	dp5 = vector <int> (n, 0);
	
	for (int i = 0; i < m; i ++) {
		int x;
		cin >> x;
		targets[x] = 1;
	}
	for (int i = 0; i < n-1; i ++) {
		int a, b;
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	
	dfs1(0, -1);
	
	dfs2(0, -1);
	
	
	for (int i = 0; i < n; i ++) {
		cout << dp1[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i ++) {
		cout << dp2[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i ++) {
		cout << dp3[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i ++) {
		cout << dp4[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < n; i ++) {
		cout << dp5[i] << " ";
	}
	cout << "\n";
	
	
	for (int i = 0; i < n; i ++) {
		ans = min(ans, dp1[i]+dp2[i]-max(dp3[i], dp5[i]));
	}
	cout << ans << "\n";
	
	return 0;
}

