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
	int n, m;
	cin >> n >> m;
	
	long long ans = 0;
	
	vector <vector <int>> arr(m, vector <int> (4, 0));
	for (int i = 0; i < n; i ++) {
		cin >> arr[i][2] >> arr[i][3] >> arr[i][0];
	}
	
	sort(arr.begin(), arr.end());
	
	DSU dsu(n);
	for (int i = 0; i < m; i ++) {
		if (dsu.unite(arr[i][2]-1, arr[i][3]-1)) {
			ans += arr[i][0];
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

