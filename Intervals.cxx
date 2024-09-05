#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

int main() {
	int n, q;
	cin >> n >> q;
	
	vector <vector <int>> rawintervals(0);
	for (int i = 0; i < n; i ++) {
		int a, b;
		cin >> a >> b;
		rawintervals.push_back({a, 0});
		rawintervals.push_back({b, 1});
	}
	sort(rawintervals.begin(), rawintervals.end());
	
	set <int> intervalends;
	map <int, int> endtostart;
	int laststart, activeintervals=0;
	for (int i = 0; i < 2*n; i ++) {
		if (rawintervals[i][1] == 0) {
			activeintervals += 1;
			if (activeintervals == 1) {
				laststart = rawintervals[i][0];
			}
		}
		else {
			activeintervals -= 1;
			if (activeintervals == 0) {
				if (i != 2*n-1 && rawintervals[i+1][0]-rawintervals[i][0] < 2) {
					i += 1;
					activeintervals = 1;
					continue;
				}
				endtostart[rawintervals[i][0]] = laststart;
				intervalends.insert(rawintervals[i][0]);
			}
		}
	}
	
	for (int i = 0; i < q; i ++) {
		int l, r;
		cin >> l >> r;
		
		if (intervalends.lower_bound(r) != intervalends.end() && endtostart[*intervalends.lower_bound(r)] <= l) {
			cout << "Y\n";
		}
		else {
			cout << "N\n";
		}
	}
	
	return 0;
}

