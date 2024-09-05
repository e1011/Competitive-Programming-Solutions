#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector <vector <int>> elementsbyfactor(n+1, vector <int> (0));
	vector <vector <int>> graph(n, vector <int> (0));
	vector <int> indegree(n, 0);
	vector <int> visited(n, 0);
	vector <int> ans(0);
	
	for (int i = 0; i < n; i ++) {
		int x, x2;
		cin >> x;
		x2 = x;
		for (int j = 2; j*j <= x; j ++) {
			if (x % j == 0) {
				elementsbyfactor[j].push_back(x2-1);
				while (x % j == 0) {
					x /= j;
				}
			}
		}
		if (x > 1) {
			elementsbyfactor[x].push_back(x2-1);
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 1; j < elementsbyfactor[i].size(); j ++) {
			graph[elementsbyfactor[i][j-1]].push_back(elementsbyfactor[i][j]);
			indegree[elementsbyfactor[i][j]] += 1;
		}
	}
	
	priority_queue <int> pq;
	for (int i = 0; i < n; i ++) {
		if (indegree[i] == 0) {
			pq.push(i);
		}
	}
	while (pq.empty() == false) {
		int node = pq.top();
		pq.pop();
		
		ans.push_back(node);
		visited[node] = 1;
		for (int i = 0; i < graph[node].size(); i ++) {
			if (visited[graph[node][i]] == 0) {
				indegree[graph[node][i]] -= 1;
				if (indegree[graph[node][i]] == 0) {
					pq.push(graph[node][i]);
				}
			}
		}
	}
	
	for (int i = 0; i < n; i ++) {
		cout << ans[i]+1;
		if (i == n-1) {
			cout << "\n";
		}
		else {
			cout << " ";
		}
	}
	
	return 0;
}

