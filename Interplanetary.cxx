#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// distance rankings by node
vector <vector <long long>> distances2;
vector <long long> distances;
vector <int> indegree;
// a before b, means a -> b
vector <vector <int>> edges;

int n, m, p, l, lastl, r, lastr;
long long ans = 0;

void dfs(int node) {
	for (int i = 0; i < edges[node].size(); i ++) {
		indegree[edges[node][i]] -= 1;
		if (edges[node][i] >= l && edges[node][i] <= r && indegree[edges[node][i]] == 0) {
			lastl = min(lastl, edges[node][i]);
			lastr = max(lastr, edges[node][i]);
			dfs(edges[node][i]);
		}
	}
}

bool comp(vector <long long> a, vector <long long> b) {
	return a[1] < b[1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m >> p;
	distances = vector <long long> (n, 0);
	distances2 = vector <vector<long long>> (n, vector <long long> (2, 0));
	indegree = vector <int> (n, 0);
	edges = vector <vector <int>> (n, vector <int> (0));
	
	for (int i = 0; i < n; i ++) {
		cin >> distances[i];
		distances2[i][0] = distances[i];
		distances2[i][1] = i;
	}
	sort(distances.begin(), distances.end());
	sort(distances2.begin(), distances2.end());
	for (int i = 0; i < n; i ++) {
		distances2[i][0] = i;
	}
	sort(distances2.begin(), distances2.end(), comp);
	
	for (int i = 0; i < m; i ++) {
		int a, b;
		cin >> a >> b;
		edges[distances2[b-1][0]].push_back(distances2[a-1][0]);
		indegree[distances2[a-1][0]] += 1;
	}
	
	
	p = distances2[p-1][0];
	l = p;
	r = p;
	lastl = p;
	lastr = p;
	
	dfs(p);
	
	while (true) {
		
		long long ldist=0, rdist=0;
		if (l-1 < 0 && r+1 == n) {
			break;
		}
		if (l-1 < 0) {
			ldist = 2000000000000000000;
		}
		else {
			ldist = distances[lastl]-distances[l-1];
		}
		if (r+1 == n) {
			rdist = 2000000000000000000;
		}
		else {
			rdist = distances[r+1]-distances[lastr];
		}
		
		if (ldist <= rdist) {
			l -= 1;
			ans = max(ans, ldist);
			if (indegree[l] == 0) {
				dfs(l);
				lastl = l;
			}
		}
		else {
			r += 1;
			ans = max(ans, rdist);
			if (indegree[r] == 0) {
				dfs(r);
				lastr = r;
			}
		}
	}
	
	
	cout << ans << "\n";
	
	return 0;
}

