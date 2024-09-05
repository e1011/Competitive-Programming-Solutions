#include <iostream>
#include <vector>

using namespace std;

long long ans = 0, ans2 = 0;

string s;
vector <vector <long long>> graph;
vector <long long> dp;
vector <vector <vector <long long>>> dp2;

void dfs(int node, int parent) {
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent) {
			dfs(graph[node][i], node);
			dp[node] += dp[graph[node][i]]+1;
		}
	}
	ans += dp[node];
	long long sum = 0;
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent) {
			sum += (dp[node]-dp[graph[node][i]]-1)*(dp[graph[node][i]]+1);
		}
	}
	ans += sum/2;
}

void dfs2(int node, int parent) {
	if (s[node] == 'B') {
		dp2[node][1][0] = 1;
	}
	else {
		dp2[node][0][1] = 1;
	}
	
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent) {
			dfs2(graph[node][i], node);
			if (s[node] == 'B') {
				for (int j = 1; j < 3; j ++) {
					for (int k = 0; k < 3; k ++) {
						dp2[node][j][k] += dp2[graph[node][i]][j-1][k];
					}
				}
			}
			else {
				for (int j = 0; j < 3; j ++) {
					for (int k = 1; k < 3; k ++) {
						dp2[node][j][k] += dp2[graph[node][i]][j][k-1];
					}
				}
			}
		}
	}
	
	long long sum = 0;
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent) {
			for (int j = 0; j < 3; j ++) {
				for (int k = 0; k < 3; k ++) {
					for (int l = 0; l < 3; l ++) {
						for (int m = 0; m < 3; m ++) {
							if (s[node] == 'B' && j > 0 && j+l < 3 && k+m < 3) {
								bool overcount = (j == 1 && k == 0);
								sum += (dp2[node][j][k]-dp2[graph[node][i]][j-1][k]-overcount)*(dp2[graph[node][i]][l][m]);
							}
							else if (s[node] == 'W' && k > 0 && j+l < 3 && k+m < 3) {
								bool overcount = (j == 0 && k == 1);
								sum += (dp2[node][j][k]-dp2[graph[node][i]][j][k-1]-overcount)*(dp2[graph[node][i]][l][m]);
							}
						}
					}
				}
			}
		}
	}
	
	for (int i = 0; i < 3; i ++) {
		for (int j = 0; j < 3; j ++) {
			if (i+j > 1) {
				ans2 += dp2[node][i][j];
			}
		}
	}
	
	ans2 += sum/2;
}

int main() {
	int n;
	cin >> n >> s;
	
	graph = vector <vector <long long>> (n, vector <long long> (0));
	dp = vector <long long> (n, 0);
	dp2 = vector <vector <vector <long long>>> (n, vector <vector <long long>> (3, vector <long long> (3, 0)));
	
	for (int i = 0; i < n-1; i ++) {
		long long a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
	}
	
	dfs(0, -1);
	dfs2(0, -1);
	
	cout << ans-ans2 << "\n";
	
	
	return 0;
}

