#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, m, k;
	cin >> n >> m >> k;
	
	vector <long long> times(k, 0), cnt(k, 0);
	vector <vector <long long>> graph(n, vector <long long> (0)), costs(n, vector <long long> (0));
	vector <vector <long long>> items(k+1, vector <long long> (n, 0));
	
	for (int i = 0; i < k; i ++) {
		cin >> times[i];
	}
	for (int i = 0; i < k; i ++) {
		cin >> cnt[i];
	}
	for (int i = 0; i < k; i ++) {
		for (int j = 0; j < cnt[i]; j ++) {
			long long x;
			cin >> x;
			items[i][x-1] = 1;
		}
	}
	
	for (int i = 0; i < m; i ++) {
		long long a, b, c;
		cin >> a >> b >> c;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
		costs[a-1].push_back(c);
		costs[b-1].push_back(c);
	}
	
	
	vector <vector <long long>> dp(n, vector <long long> (k+1, -1));
	priority_queue <vector <long long>, vector <vector <long long>>, greater <vector <long long>>> pq;
	pq.push({0, 0, 0});
	
	while (pq.empty() == false) {
		long long dist = pq.top()[0], node = pq.top()[1], itmcnt = pq.top()[2];
		pq.pop();
		
		if (dp[node][itmcnt] == -1) {
			dp[node][itmcnt] = dist;
			
			if (itmcnt < k) {
				for (int i = 0; i < graph[node].size(); i ++) {
					int counter = 0;
					while (items[itmcnt+counter][graph[node][i]]) {
						counter += 1;
					}
					if (dp[graph[node][i]][itmcnt+counter] == -1) {
						pq.push({dist+costs[node][i], graph[node][i], itmcnt+counter});
					}
				}
				
				if (dp[node][itmcnt+1] == -1) {
					pq.push({dist+times[itmcnt], node, itmcnt+1});
				}
			}
		}
	}
	
	
	long long ans = 1000000000000000000;
	for (int i = 0; i < n; i ++) {
		if (dp[i][k] != -1) {
			ans = min(ans, dp[i][k]);
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}
