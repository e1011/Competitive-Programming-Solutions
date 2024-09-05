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
	int n, m, ans=1;
	cin >> n >> m;
	
	vector <vector <int>> graph(n, vector <int> (0));
	vector <string> elevatorplan(n, "");
	for (int i = 0; i < n; i ++) {
		cin >> elevatorplan[i];
	}
	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < n-1; j ++) {
			for (int k = j+1; k < n; k ++) {
				if (elevatorplan[j][i] == '1' && elevatorplan[k][i] == '1') {
					graph[j].push_back(k);
					graph[k].push_back(j);
					//cout << j << ", " << k << "\n";
				}
			}
		}
	}
	
	for (int i = 0; i < n-1; i ++) {
		DSU dsu(n);
		for (int j = i+1; j < n; j ++) {
			for (int k = 0; k < graph[j].size(); k ++) {
				if (graph[j][k] == 1 && k >= i && k <= j) {
					//cout << j << ", " << k << "\n";
					dsu.unite(j, k);
				}
			}
			//cout << dsu.size(i) << ", " << i << ", " << j << "\n";
			if (dsu.size(i) == j-i+1) {
				ans = max(j-i+1, ans);
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

