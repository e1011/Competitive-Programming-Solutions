#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector <vector <int>> graph, indexes;
vector <int> visited, indices(0), nodes, traversal1(0), traversal2(0);

void dfs(int node, int parent) {
	visited[node] = 1;
	for (int i = 0; i < graph[node].size(); i ++) {
		//cout << node << ", " << graph[node][i] << ", " << visited[graph[node][i]] << "\n";
		if (visited[graph[node][i]]) {
			for (int j = (int)traversal1.size()-1; j >= 0; j --) {
				if (traversal2[j] == node) {
					break;
				}
				indices.push_back(traversal1[j]);
			}
		}
		else {
			traversal1.push_back(indexes[node][i]);
			traversal2.push_back(graph[node][i]);
			dfs(graph[node][i], node);
		}
	}
}

int main() {
	int n, m;
	cin >> n >> m;
	
	graph = vector <vector <int>> (n, vector <int> (0));
	indexes = graph;
	visited = vector <int> (n, 0);
	
	for (int i = 0; i < m; i ++) {
		int a, b;
		cin >> a >> b;
		graph[a-1].push_back(b-1);
		graph[b-1].push_back(a-1);
		indexes[a-1].push_back(i);
		indexes[b-1].push_back(i);
	}
	
	dfs(0, -1);
	
	vector <int> ans(m, 0);
	
	ans[indices[0]] = 2;
	for (int j = 1; j < indices.size(); j ++) {
		ans[indices[j]] = (j % 2);
	}
	
	for (int i = 0; i < m; i ++) {
		if (ans[i] == 0) {
			cout << "R";
		}
		else if (ans[i] == 1) {
			cout << "B";
		}
		else {
			cout << "G";
		}
	}
	
	return 0;
}

