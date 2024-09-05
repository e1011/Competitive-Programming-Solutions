#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int counter = 0;
vector <int> e(0), graph, indegree, currentcycle(0), cycleindex, visited;

void dfs(int node) {
	currentcycle.push_back(node);
	if (visited[node] == 0) {
		visited[node] = 1;
	}
	else if (visited[node] == 1) {
		counter += 1;
		for (int i = (int)currentcycle.size()-2; i >= 0; i --) {
			cycleindex[currentcycle[i]] = counter;
			if (currentcycle[i] == node) {
				break;
			}
		}
		return;
	}
	if (visited[graph[node]] != 2) {
		dfs(graph[node]);
	}
	
	visited[node] = 2;
}

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

bool comp(int a, int b) {
	return cycleindex[a] < cycleindex[b];
}

int main() {
	int n, q, ccs;
	cin >> n >> q;
	ccs = n;
	
	graph = vector <int> (n, 0);
	indegree = vector <int> (n, 0);
	visited = vector <int> (n, 0);
	cycleindex = vector <int> (n, 0);
	e = vector <int> (n, -1);
	
	for (int i = 0; i < n; i ++) {
		cin >> graph[i];
		graph[i] -= 1;
		indegree[graph[i]] += 1;
		if (unite(i, graph[i])) {
			ccs -= 1;
		}
	}
	
	for (int i = 0; i < n; i ++) {
		if (visited[i] == 0) {
			currentcycle = vector <int> (0);
			dfs(i);
		}
	}
	
	
	vector <int> indegree2 = indegree;
	for (int i = 0; i < q; i ++) {
		int x, ans = ccs;
		cin >> x;
		vector <int> s(x, 0);
		for (int j = 0; j < x; j ++) {
			cin >> s[j];
			s[j] -= 1;
			indegree2[graph[s[j]]] -= 1;
		}
		
		sort(s.begin(), s.end(), comp);
		for (int j = 0; j < x; j ++) {
			if (indegree2[s[j]] == 0) {
				ans -= 1;
			}
			if (cycleindex[s[j]] == 0) {
				ans += 1;
			}
			else if (j != 0 && cycleindex[s[j-1]] == cycleindex[s[j]]) {
				ans += 1;
			}
		}
		
		for (int j = 0; j < x; j ++) {
			indegree2[graph[s[j]]] = indegree[graph[s[j]]];
		}
		cout << ans << "\n";
	}
	
	
	return 0;
}

