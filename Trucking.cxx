#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n, m, k, ans=1000000000;
	cin >> n >> m >> k;
	
	vector <vector <int>> graph(n, vector <int> (0));
	vector <vector <int>> costs(n, vector <int> (0));
	vector <int> dp(n, -1);
	for (int i = 0; i < m; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
		costs[a-1].push_back(c);
		costs[b-1].push_back(c);
	}
	
	priority_queue <vector <int>> pq;
	pq.push({1000000000, 0});
	while (pq.empty() == false) {
		int dist = pq.top()[0], node = pq.top()[1];
		pq.pop();
		if (dp[node] == -1) {
			dp[node] = dist;
			for (int i = 0; i < graph[node].size(); i ++) {
				pq.push({min(dist, costs[node][i]), graph[node][i]});
			}
		}
	}
	
	for (int i = 0; i < k; i ++) {
		int d;
		cin >> d;
		ans = min(ans, dp[d-1]);
		//cout << d << ", " << dp[d-1] << "\n";
	}
	
	cout << ans << "\n";
	
	return 0;
}

