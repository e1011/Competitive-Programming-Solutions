#include <iostream>
#include <vector>

using namespace std;

vector <int> e;

int get(int node) {
	if (e[node] < 0) {
		return node;
	}
	else {
		e[node] = get(e[node]);
		return e[node];
	}
}

bool unite(int node1, int node2) {
	int a = get(node1), b = get(node2);
	if (a == b) {
		return 0;
	}
	if (e[a] > e[b]) {
		swap(a, b);
	}
	
	e[b] += e[a];
	e[a] = b;
	return 1;
}

int main() {
	int n, m;
	cin >> n >> m;
	
	vector <vector <int>> graph(n, vector <int> (0));
	vector <int> ans(n, 0);
	e = vector <int> (n, -1);
	
	for (int i = 0; i < m; i ++) {
		int a, b;
		cin >> a >> b;
		if (a > b) {
			swap(a, b);
		}
		graph[a-1].push_back(b-1);
	}
	
	
	int unites = 0;
	for (int i = n-1; i >= 0; i --) {
		ans[i] = n-1-i-unites;
		for (int j = 0; j < graph[i].size(); j ++) {
			unites += unite(i, graph[i][j]);
		}
	}
	
	for (int i = 0; i < n; i ++) {
		cout << ans[i] << "\n"; 
	}
	
	
	return 0;
}

