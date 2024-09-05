#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
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
	//freopen("snowboots.in", "r", stdin);
	//freopen("snowboots.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, b;
	cin >> n >> b;
	
	vector <vector <int>> sortedtiles(n, vector <int> (2, 0));
	vector <int> tiles(n, 0);
	set <int> tiles2;
	for (int i = 0; i < n; i ++) {
		cin >> tiles[i];
		sortedtiles[i][0] = tiles[i];
		sortedtiles[i][1] = i;
		tiles2.insert(tiles[i]);
	}
	sort(sortedtiles.begin(), sortedtiles.end());
	reverse(sortedtiles.begin(), sortedtiles.end());
	
	
	map <int, int> mingap;
	DSU dsu(n);
	for (int i = 0; i < n; i ++) {
		if (sortedtiles[i][1] != 0 && tiles[sortedtiles[i][1]-1] >= sortedtiles[i][0]) {
			dsu.unite(sortedtiles[i][1], sortedtiles[i][1]-1);
		}
		if (sortedtiles[i][1] != n-1 && tiles[sortedtiles[i][1]+1] >= sortedtiles[i][0]) {
			dsu.unite(sortedtiles[i][1], sortedtiles[i][1]+1);
		}
		mingap[sortedtiles[i][0]] = max(mingap[sortedtiles[i][0]], dsu.size(sortedtiles[i][1]));
	}
	
	for (int i = 0; i < b; i ++) {
		int a, b;
		cin >> a >> b;
		if (tiles2.upper_bound(a) == tiles2.end()) {
			cout << "1\n";
		}
		else {
			cout << (b > mingap[*tiles2.upper_bound(a)]) << "\n";
		}
	}
	
	
}

// a "gap" cannot be passed with boots 
// if the size is greater than the boots distance
// and every tile in the gap is deeper than the boots depth
// maintain a sorted list of tiles by depth
// process shallow ones first
// for every tile, add adjacent edges to dsu iff they are activated
// for every depth, biggest component size of dsu will be max size for depth
// loop through boots, depth is equal to biggest depth smaller than the boots
// check if step dist exceeds max size
