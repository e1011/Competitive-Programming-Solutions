#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, a, b, xnode1, xnode2, ans=1000000000, found1 = 0;
vector <vector <int>> graph;
vector <int> path(0);

int findpath(int node, int parent) {
	int found = 0;
	if (node == b) {
		found1 = 1;
		found = 1;
	}
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent && found1 != 1) {
			if (findpath(graph[node][i], node)) {
				found = 1;
			}		
		}
	}
	if (found) {
		path.push_back(node);
	}
	return found;
}

int dfs(int node, int parent) {
	int val = 0;
	vector <int> values(0);
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent && !((node == xnode1 && graph[node][i] == xnode2) || (node == xnode2 && graph[node][i] == xnode1))) {
			values.push_back(dfs(graph[node][i], node));
		}
	}
	
	sort(values.begin(), values.end());
	for (int i = 0; i < values.size(); i ++) {
		val = max(val, values[i]+(int)values.size()-i);
	}
	
	return val;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> a >> b;
	a -= 1;
	b -= 1;
	
	graph = vector <vector <int>> (n, vector <int> (0));
	for (int i = 0; i < n-1; i ++) {
		int x, y;
		cin >> x >> y;
		graph[x-1].push_back(y-1);
		graph[y-1].push_back(x-1);
	}
	
	findpath(a, -1);
	int l=0, r=path.size()-1;
	while (l < r) {
		int mid = (l+r+1)/2;
		xnode1 = path[mid-1];
		xnode2 = path[mid];
		int avalue = dfs(a, -1), bvalue = dfs(b, -1);
		if (avalue > bvalue) {
			l = mid;
		}
		else {
			r = mid-1;
		}
		ans = min(ans, max(avalue, bvalue));
	}
	
	cout << ans << "\n";
	
	return 0;
}

