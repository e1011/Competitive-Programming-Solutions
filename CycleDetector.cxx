#include <iostream>
#include <vector>

using namespace std;

int loopcounter = 0;
vector <vector <int>> graph;
vector <int> visited;

void dfs(int node) {
	visited[node] = 1;
	for (int i = 0; i < graph[node].size(); i ++) {
		if (visited[graph[node][i]] == 0) {
			dfs(graph[node][i]);
		}
		else if (visited[graph[node][i]] == 1) {
			loopcounter += 1;
		}
	}
	visited[node] = 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, e;
	cin >> n >> e;
	
	graph = vector <vector <int>> (n, vector <int> (0));
	visited = vector <int> (n, 0);
	
	for (int i = 0; i < e; i ++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
	}
	
	dfs(0);
	
	if (loopcounter == 0) {
		cout << "No Infinite Loops\n";
	}
	else if (loopcounter == 1) {
		cout << "Infinite Loop Present\n";
	}
	else {
		cout << "Infinite Loops Present\n";
	}
	
	return 0;
}

