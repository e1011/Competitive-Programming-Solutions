#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct DSU {
	vector<int> e;
	DSU(int N) { e = vector<int>(N, -1); }

	int get(int x) { return e[x] < 0 ? x : e[x] = get(e[x]); }

	int size(int x) { return -e[get(x)]; }

	bool unite(int x, int y) {
		x = get(x), y = get(y);
		if (x == y) return false;
		if (e[x] > e[y]) swap(x, y);
		e[x] += e[y]; e[y] = x; return true;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, ans1=0, ans2=0;
	cin >> n;
	vector <vector <int>> costs(vector <vector <int>> (1001, vector <int> (1001, -1)));
	vector <vector <int>> edges1(vector <vector <int>> (1001, vector <int> (1001, -1)));
	vector <vector <int>> edges2(vector <vector <int>> (1001, vector <int> (1001, -1)));
	vector <vector <int>> edges3(0);
	
	for (int i = 0; i < n; i ++) {
		int k;
		cin >> k;
		vector <int> pen(k, 0);
		for (int j = 0; j < k; j ++) {
			cin >> pen[j];
			pen[j] -= 1;
		}
		for (int j = 0; j < k; j ++) {
			int c, a=min(pen[j], pen[(j+1)%k]), b=max(pen[j], pen[(j+1)%k]);
			cin >> c;
			costs[a][b] = c;
			if (edges1[a][b] == -1) {
				edges1[a][b] = i;
			}
			else {
				edges2[a][b] = i;
			}
		}
	}
	
	for (int i = 0; i < 1001; i ++) {
		for (int j = 0; j < 1001; j ++) {
			if (i <= j && edges1[i][j] != -1) {
				if (edges2[i][j] != -1) {
					edges3.push_back({costs[i][j], edges1[i][j], edges2[i][j]});
				}
				else {
					edges3.push_back({costs[i][j], edges1[i][j], n});
				}
			}
		}
	}
	
	sort(edges3.begin(), edges3.end());
	DSU dsu(n+1);
	
	for (int i = 0; i < edges3.size(); i ++) {
		if (dsu.unite(edges3[i][1], edges3[i][2])) {
			ans1 += edges3[i][0];
		}
	}
	dsu = DSU(n);
	for (int i = 0; i < edges3.size(); i ++) {
		if (edges3[i][1] != n && edges3[i][2] != n && dsu.unite(edges3[i][1], edges3[i][2])) {
			ans2 += edges3[i][0];
		}
	}
	if (dsu.size(0) != n) {
		ans2 = 1000000000;
	}
	
	cout << min(ans1, ans2) << "\n";
	
	return 0;
}

