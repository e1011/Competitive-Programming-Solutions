#include <iostream>
#include <vector>

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
	freopen("closing.in", "r", stdin);
	freopen("closing.out", "w", stdout);
	
	int n, m;
	cin >> n >> m;
	
	vector <vector <int>> edges(n, vector <int> (0));
	for (int i = 0; i < m; i ++) {
		int a, b;
		cin >> a >> b;
		edges[a-1].push_back(b-1);
		edges[b-1].push_back(a-1);
	}
	
	vector <int> order(n, 0);
	for (int i = 0; i < n; i ++) {
		cin >> order[i];
		order[i] -= 1;
	}
	
	DSU dsu(n);
	vector <int> seen(n, 0);
	vector <int> ans(n, 0);
	for (int i = n-1; i >= 0; i --) {
		for (int j = 0; j < edges[order[i]].size(); j ++) {
			if (seen[edges[order[i]][j]] == 1) {
				dsu.unite(order[i], edges[order[i]][j]);
			}
		}
		seen[order[i]] = 1;
		ans[i] = (dsu.size(order[i]) == n-i);
	}
	
	for (int i = 0; i < n; i ++) {
		if (ans[i]) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
	}
	
	
	return 0;
}

