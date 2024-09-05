#include <iostream>
#include <vector>

vector <vector <int>> graph;
vector <int> visited;
vector <int> cycle(0);
int cyclecount = 0;

dfs(int node, int parent) {
	for (int i = 0; i < graph[node].size(); i ++) {
		if (visited[graph[node][i]] == 0 && graph[node][i] != parent) {
			if (graph[node][i] != cycle[0]) {
				cycle.push_back(graph[node][i]);
				visited[graph[node][i]] = 1;
				dfs(graph[node][i], node);
			}
			else {
				for (int i = 0; i < cycle.size(); i ++) {
					cyclecount += 1;
					cycle[i] = cyclecount;
				}
			}
		}
	}
}

int main(){
	int n;
	cin >> n;
	
	graph = vector <vector <int>> (n, vector <int> (0));
	visited = vector <int> (n, 0);
	cycle = vector <int> (n, 0);
	
	for (int i = 0; i < n; i ++) {
		int x;
		cin >> x;
		if (i == 0) {
			cout << i << " " << x << "\n";
		}
		graph[i].push_back(x-1);
	}
	
	for (int i = 0; i < n; i ++) {
		if (visited[i] == 0) {
			dfs(i, -1);
		}
	}
	
	for (int i = 0; i < n; i ++) {
		if (cycle[i] != 0) {
		
		}
	}
	
	cout << sum << "\n";
	
	return 0;
}

