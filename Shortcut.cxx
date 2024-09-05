#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int>> newgraph;
vector <int> cows;

int dfs(int node) {
	for (int i = 0; i < newgraph[node].size(); i ++) {
		cows[node] += dfs(newgraph[node][i]);
	}
	return cows[node];
}

int main() {	
	freopen("shortcut.in", "r", stdin);
	freopen("shortcut.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, t;
	cin >> n >> m >> t;
	
	vector <vector <int>> graph(n, vector <int> (0));
	vector <vector <int>> costs(n, vector <int> (0));
	vector <int> distances(n, -1);
	vector <int> parents(n, -1);
	newgraph = vector <vector <int>> (n, vector <int> (0));
	cows = vector <int>(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> cows[i];
	}
	for (int i = 0; i < m; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a-1].push_back(b-1);
		costs[a-1].push_back(c);
		graph[b-1].push_back(a-1);
		costs[b-1].push_back(c);
	}
	
	priority_queue <vector <int>, vector <vector <int>>, greater <vector <int>>> pq;
	pq.push({0, 0, -1});
	while (pq.empty() == false) {
		int dist = pq.top()[0], node=pq.top()[1], parent=pq.top()[2];
		pq.pop();
		if (distances[node] == -1) {
			distances[node] = dist;
			parents[node] = parent;
			for (int i = 0; i < graph[node].size(); i ++) {
				pq.push({dist+costs[node][i], graph[node][i], node});
			}
		}
		else if (distances[node] == dist && parents[node] > parent) {
			parents[node] = node;
		}
	}
	
	for (int i = 0; i < n; i ++) {
		if (parents[i] != -1) {
			newgraph[parents[i]].push_back(i);
		}
	}
	
	dfs(0);
	
	long long ans=0;
	for (int i = 0; i < n; i ++) {
		ans = max(ans, (long long)(distances[i]-t)*(long long)cows[i]);
	}
	cout << ans << "\n";
	
	return 0;
}

