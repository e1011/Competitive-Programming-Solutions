#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	// get representive component (uses path compression)
	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {  // union by size
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x;
		return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, m, ans;
	cin >> n >> m;
	
	ans = n;
	DSU dsu(n);
	vector <vector <int>> graph(n, vector <int> (0));
	vector <int> processed(n, 0);
	for (int i = 0; i < m; i ++) {
		char c;
		int a, b;
		cin >> c >> a >> b;
		if (c == 'F') {
			ans -= dsu.unite(a-1, b-1);
		}
		else {
			graph[a-1].push_back(b-1);
			graph[b-1].push_back(a-1);
		}
	}
	
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < graph[i].size(); j ++) {
			if (processed[graph[i][j]] == 0) {
				processed[graph[i][j]] = 1;
				for (int k = 0; k < graph[graph[i][j]].size(); k ++) {
					ans -= dsu.unite(i, graph[graph[i][j]][k]);
				}
			}
		}
	}
	
	cout << ans << "\n";
	
	
	return 0;
}


