#include <iostream>
#include <vector>

using namespace std;

vector <vector <int>> graph;
vector <int> dp1;
vector <int> dp2;
vector <int> l;
vector <int> r;

void dfs1(int node) {
	for (int i = 0; i < graph[node].size(); i ++) {
		dfs1(graph[node][i]);
		dp1[node] = max(l[node], dp1[graph[node][i]]);
		dp2[node] = min(r[node], dp2[graph[node][i]]);
	}
}

int main() {
	int t, b;
	cin >> t >> b;
	
	for (int _ = 0; _ < t; _ ++) {
		int n, ans=0;
		cin >> n;
		
		graph = vector <vector <int>> (n, vector <int> (0));
		dp1 = vector <int> (n, -1000000000);
		dp2 = vector <int> (n, 1000000000);
		l = vector <int> (n, 0);
		r = vector <int> (n, 0);
		for (int i = 1; i < n; i ++) {
			int a;
			cin >> a;
			graph[a-1].push_back(i);
		}
		for (int i = 0; i < n; i ++) {
			cin >> l[i] >> r[i];
		}
		
		dfs1(0);
		for (int i = 0; i < n; i ++) {
			cout << dp1[i] << ", " << dp2[i] << "\n";
			ans = max(ans, max(0, dp1[i]-dp2[i]));
		}
		cout << ans << "\n";
	}
	
	
	return 0;
}

