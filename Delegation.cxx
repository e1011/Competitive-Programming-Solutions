#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> graph;
vector <int> dp;
bool works;

void dfs(int node, int parent, int k) {
	if (graph[node].size() == 1) {
		dp[node] = k-1;
	}
	else {
		int s1=0, s2=0;
		for (int i = 0; i < graph[node].size(); i ++) {
			if (works && graph[node][i] != parent && dp[graph[node][i]] != 0) {
				dfs(graph[node][i], node, k);
				s1 += 1;
				s2 += dp[graph[node][i]];
			}
		}
		if (s1 > 2) {
			works = 0;
		}
		else if (s1 == 2 && (s2+1)%k != 0) {
			works = 0;
		}
		else {
			dp[node] = (s2+1)%k;
		}
	}
}

int main() {
	int n;
	cin >> n;
	
	graph = vector <vector <int>> (n, vector <int> (0));
	dp = vector <int> (n, 0);
	for (int i = 0; i < n-1; i ++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	
	vector <int> ans(n, 0);
	for (int i = 1; i < n; i ++) {
		if ((n-1) % i == 0) {
			works = 1;
			dfs(0, i, -1);
			if (dp[0] != 0) {
				works = 0;
			}
			ans[i] = works;
		}
	}
	
	for (int i = 1; i < n; i ++) {
		cout << ans[i];
	}
	cout << "\n";
	
	return 0;
	
}
