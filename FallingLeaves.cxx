#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int>> graph;
vector <int> dp1, dp2;

void dfs(int node, int parent) {
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent) {
			dfs(graph[node][i], node);
			dp1[node] *= dp1[graph[node][i]];
			dp1[node] %= 1000000007;
			dp2[node] += dp2[graph[node][i]];
		}
	}
}


int main() {
	int n, k;
	cin >> n >> k;
	
	vector <int> color(n, 0);
	graph = vector <vector <int>> (n, vector <int> (0));
	for (int i = 0; i < n; i ++) {
		cin >> color[i];
		color[i] -= 1;
	}
	for (int i = 0; i < n-1; i ++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	
	
	for (int i = 0; i < k; i ++) {
		long long ans = 1;
		vector <int> dist(n, -1);
		vector <int> critical(0);
		dp1 = vector <int>(n, 1);
		dp2 = vector <int>(n, 1);
		
		queue <vector <int>> q;
		for (int j = 0; j < n; j ++) {
			if (color[j] == k) {
				q.push({j, 0});
			}
		}
		while (q.empty() == false) {
			int node = q.front()[0], distance = q.front()[1];
			q.pop();
			
			dist[node] = distance;
			for (int j = 0; j < graph[node].size(); j ++) {
				if (dist[graph[node][j]] == -1) {
					q.push({graph[node][j], distance+1});
				}
			}
		}
		
		int maxnode, maxval=0;
		for (int j = 0; j < n; j ++) {
			if (dist[j] > maxval) {
				maxval = dist[j];
				maxnode = j;
			}
		}
		
		dfs(maxnode, -1);
		queue <int> q2;
		q2.push(maxnode);
		while (q2.empty() == false) {
			int node = q2.front();
			q2.pop();
			
			dist[node] = -2;
			if (color[node] == i) {
				critical.push_back(node);
			}
			else {
				for (int j = 0; j < graph[node].size(); j ++) {
					if (dist[node] != -2) {
						q2.push(graph[node][j]);
					}
				}
			}
		}
		
		long long sum = 0;
		for (int j = 0; j < critical.size(); j ++) {
			ans *= dp1[critical[j]];
			ans %= 1000000007;
			sum += dp2[critical[j]];
		}
		for (int j = 1; j <= sum; j ++) {
			ans *= j;
			ans %= 1000000007;
		}
		cout << ans << "\n";
	}
	
	return 0;
}

