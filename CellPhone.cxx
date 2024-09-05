#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> nodes(0), ans(0), visited;
vector <vector <int>> graph;

void dfs(int node, int parent) {
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent && visited[graph[node][i]] == 0) {
			visited[graph[node][i]] = 1;
			dfs(graph[node][i], parent);
		}
	}
	ans.push_back(node);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, works=1;
	cin >> n;
	vector <int> start(n, 0);
	vector <int> target(n, 0);
	
	for (int i = 0; i < n; i ++) {
		cin >> start[i];
	}
	for (int i = 0; i < n; i ++) {
		cin >> target[i];
	}
	
	graph = vector <vector <int>> (n, vector <int> (0));
	visited = vector <int> (n, 0);
	for (int i = 0; i < n; i ++) {
		if ((start[i] == -1 && target[i] != -1) || (start[i] != -1 && target[i] == -1)) {
			works = 0;
			break;
		}
		else if (start[i] != target[i]) {
			nodes.push_back(i);
			if (start[target[i]-1]-1 != i) {
				graph[target[i]-1].push_back(i);
			}
		}
	}
	
	for (int i = (int)nodes.size()-1; i >= 0; i --) {
		if (visited[nodes[i]] == 0) {
			visited[nodes[i]] = 1;
			dfs(nodes[i], -1);
		}
	}
	reverse(ans.begin(), ans.end());
	
	if (works) {
		cout << nodes.size() << "\n";
		for (int i = 0; i < ans.size(); i ++) {
			cout << ans[i]+1 << " " << target[ans[i]] << "\n";
		}
	}
	else {
		cout << "-1\n";
	}
	
	return 0;
}

