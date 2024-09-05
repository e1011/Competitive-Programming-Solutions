#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	
	vector <vector <int>> graph(n, vector <int> (0));
	vector <vector <int>> costs(n, vector <int> (0));
	vector <int> dp(n, -1);
	
	for (int i = 0; i < m; i ++) {
		int a, b, p;
		cin >> a >> b >> p;
		
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);		
		costs[a-1].push_back(p);
		costs[b-1].push_back(p);
	}
	
	priority_queue <vector <int>> pq;
	pq.push({1000000000, 0});
	while (pq.empty() == false) {
		int cost = pq.top()[0], node = pq.top()[1];
		pq.pop();
		if (dp[node] == -1) {
			dp[node] = cost;
			for (int i = 0; i < graph[node].size(); i ++) {
				if (dp[graph[node][i]] == -1) {
					pq.push({min(cost, costs[node][i]), graph[node][i]});
				}
			}
		} 
	}
	
	cout << "0\n";
	for (int i = 1; i < n; i ++) {
		cout << dp[i] << "\n";
	}
	
	
	return 0;
}

