#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector <vector <int>> dp(0);
vector <vector <int>> graph(0);
vector <vector <int>> costs(0);

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q, k;
	cin >> n >> q;
	
	graph = vector <vector <int>> (n, vector <int> (0));
	costs = vector <vector <int>> (n, vector <int> (0));
	for (int i = 0; i < n-1; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
		costs[a-1].push_back(c);
		costs[b-1].push_back(c);
	}
	
	k = 2*costs[0][0];
	
	dp = vector <vector <int>> (n, vector <int> (k, -1));
	priority_queue <vector <int>, vector <vector <int>>, greater <vector<int>>> pq;
	pq.push({0, 0, 0});
	
    while (!pq.empty()) {
        int mod=pq.top()[0], rem=pq.top()[1], node=pq.top()[2];
        pq.pop();

        if (dp[node][rem] == -1) {
            dp[node][rem] = mod;
            for (int i = 0; i < graph[node].size(); i ++) {
				int x = dp[graph[node][i]][(rem+costs[node][i]) % k];
				if (x == -1 || mod+(rem+costs[node][i])/k < x) {
					pq.push({mod+(rem+costs[node][i])/k, (rem+costs[node][i]) % k, graph[node][i]});
				}
            }
        }
    }
	
	for (int i = 0; i < q; i ++) {
		int a, b;
		cin >> a >> b;
		if (b > 1000) {
			throw;
		}
		if (dp[a-1][b % k] != -1 && dp[a-1][b % k] <= b/k) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
	return 0;
}

