#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m, p, t;
	cin >> n >> m >> p >> t;
	
	// stores outgoing edges
	vector <vector <int>> nodes(n, vector <int> (0));
	// stores earliest and latest leaving, earliest and latest arrival, destination
	vector <vector <int>> edges(m, vector <int> (5, 0));
	vector <int> dp(n+1, -1);
	
	for (int i = 0; i < m; i ++) {
		int x;
		cin >> x;
		nodes[x-1].push_back(i);
		
		cin >> edges[i][4] >> edges[i][0] >> edges[i][1] >> edges[2] >> edges[i][3];
		edges[i][4] -= 1;
	}	
	edges.push_back({-1, -1, 0, 0, 0});
	edges.push_back({t, t, t, t, n});
	nodes[n-1].push_back(m+1);
	
	priority_queue <vector <int>, vector <vector <int>>, greater <vector <int>>> pq;
	pq.push({0, m});
	while (pq.empty() == false) {
		int cost=pq.front()[0], edge=pq.front()[1];
		pq.pop();
		if (dp[edges[edge][4]] == n-1) {
			dp[edges[edge][4]] = cost;
			for (int i = 0; i < nodes[edges[edge][4]].size(); i ++) {
				if (dp[edges[nodes[edges[edge][4]][i]][4]] == -1 && edges[edge][3] <= edges[nodes[edges[edge][4]][i]][0]) {
					pq.push({cost+edges[nodes[edges[edge][4]][i]][1]-edges[edge][2], nodes[edges[edge][4]][i]});
				}
			}
		}
		
	}
	
	cout << dp[n] << "\n";
	
	return 0;
}

// dijkstra on edges, with minimum waiting time as the value. use edges cuz if use nodes, dont know arrival time
// edges are connected to other edges via nodes
// for each connection, cost += latest leaving - earliest arrival
// traversing a connection is only possible if latest arrival < earlist leaving

