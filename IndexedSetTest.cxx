#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iostream>
#include <vector>
#include <set>

using namespace std;
using namespace __gnu_pbds;

template<class T>
using Tree = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

// stores ores at each node
vector <multiset <int>> oresdp1;
// stores frequencies of ores at each node. {frequency, ore type} to avoid collision
vector <Tree <vector <int>>> oresdp2;
vector <vector <int>> ores;
vector <vector <int>> graph;
vector <int> ans;

void dfs(int node, int parent) {
	int maxchild=0, maxindex=-1;
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != parent) {
			dfs(graph[node][i], node);
			if (oresdp1[graph[node][i]].size() > maxchild) {
				maxchild = oresdp1[graph[node][i]].size();
				maxindex = graph[node][i];
			}
		}
	}
	
	if (maxindex != -1) {
		swap(oresdp1[node], oresdp1[maxindex]);
		oresdp2[node].swap(oresdp2[maxindex]);
		ans[node] = ans[maxindex];
	}
	for (int i = 0; i < graph[node].size(); i ++) {
		if (graph[node][i] != maxindex) {
			for (int j: oresdp1[graph[node][i]]) {
				if (oresdp1[node].count(j) == 0) {
					oresdp1[node].insert(j);
					oresdp2[node].insert({1, j});
				}
				else {
					oresdp2[node].erase({oresdp1.count(j), j});
					oresdp1[node].insert(j);
					oresdp2[node].insert({oresdp1.count(j), j});
				}
				ans[node] = max(ans[node], oresdp1[node].count(j)*(oresdp2[node].size()-oresdp2[node].find_by_order({oresdp1.count(j), -1})));
			}
		}
	}
	
	for (int j: ores[node]) {
		if (oresdp1[node].count(j) == 0) {
			oresdp1[node].insert(j);
			oresdp2[node].insert({1, j});
		}
		else {
			oresdp2[node].erase({oresdp1.count(j), j});
			oresdp1[node].insert(j);
			oresdp2[node].insert({oresdp1.count(j), j});
		}
		ans[node] = max(ans[node], oresdp1[node].count(j)*(oresdp2[node].size()-oresdp2[node].find_by_order({oresdp1.count(j), -1})));
	}
}

int main() {
	int n;
	cin >> n;
	
	graph = vector <int> (n, vector <int> (0));
	ores = vector <vector <int>> (n, vector <int> (0));
	oresdp1 = vector <multiset <int>> (n, multiset <int>);
	oresdp2 = vector <Tree <vector <int>>> (n, Tree <vector <int>>);
	ans = vector <int> (n, 0);
	
	for (int i = 0; i < n-1; i ++) {
		int x;
		cin >> x;
		if (x != 0) {
			graph[i].push_back(x-1);
			graph[x-1].push_back(i);
		}
	}
	
	for (int i = 0; i < n; i ++) {
		int m;
		cin >> m;
		ores[i] = vector <int> (m, 0);
		for (int j = 0; j < m; j ++) {
			cin >> ores[i][j];
		}
	}
	
	dfs(0, -1);
	
	for (int i = 0; i < n; i ++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	
	
	return 0;
}

