#include <iostream>
#include <vector>
#include <set>

using namespace std;

vector <vector <int>> graph;
vector <int> powers, visited;

long long dfs(int node, long long res) {
	res *= powers[node];
	res %= 1000000007;
	visited[node] = 1;
	for (int i = 0; i < graph[node].size(); i ++) {
		if (visited[graph[node][i]] == 0) {
			res = dfs(graph[node][i], res);
		}
	}
	return res;
}

int main() {
	int n, m, z, ans=0;
	cin >> n;
	graph = vector <vector <int>> (n, vector <int> (0));
	powers = vector <int> (n, 0);
	vector <vector <int>> edges(0);
	visited = vector <int> (n, 0);
	set <vector <int>> s;
	
	for (int i = 0; i < n; i ++) {
		cin >> powers[i];
	}
	for (int i = 0; i < n-1; i ++) {
		int a, b;
		cin >> a >> b;
		edges.push_back({min(a-1, b-1), max(a-1, b-1)});
	}
	
	cin >> m;
	for (int i = 0; i < m-1; i ++) {
		int a, b, c;
		cin >> a >> b >> c;
		s.insert({min(b-1, c-1), max(b-1, c-1)});
	}
	cin >> z;
	
	for (int i = 0; i < n-1; i ++) {
		if (s.count(edges[i]) == 0) {
			graph[edges[i][0]].push_back(edges[i][1]);
			graph[edges[i][1]].push_back(edges[i][0]);
		}
	}
	
	for (int i = 0; i < n; i ++) {
		if (visited[i] == 0) {
			ans += dfs(i, 1);
			ans %= 1000000007;
		}
	}
	cout << ans << "\n";
	
	
	return 0;
}

