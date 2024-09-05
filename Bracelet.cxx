#include <iostream>
#include <vector>

using namespace std;

int main() {
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i ++) {
		int n, m, works=1;
		cin >> n >> m;
		
		vector <vector <int>> lines(0);
		for (int j = 0; j < m; j ++) {
			int k;
			cin >> k;
			vector <int> line(k, 0);
			for (int l = 0; l < k; l ++) {
				cin >> line[l];
				line[l] -= 1;
			}
			lines.push_back(line);
		}
		
		
		// check for empty gap
		for (int j = 0; j < n; j ++) {
			int seen2 = 0;
			for (int k = 0; k < m; k ++) {
				int seen1 = 0;
				for (int l = 0; l < lines[k].size(); l ++) {
					if (lines[k][l] == j) {
						seen1 = 1;
					}
				}
				if (seen2 == 0 && seen1 == 1) {
					seen2 = 1;
				}
				if (seen2 == 1 && seen1 == 0) {
					seen2 = 2;
				}
				if (seen2 == 2 && seen1 == 1) {
					seen2 = 3;
				}
			}
			if (seen2 == 3) {
				works = 0;
			}
		}
		
		
		// check for intersection in single line
		for (int j = 0; j < n; j ++) {
			for (int k = j+1; k < n; k ++) {
				for (int l = 0; l < m; l ++) {
					int seen1 = 0, seen2 = 0;
					for (int x = 0; x < lines[l].size(); x ++) {
						if (lines[l][x] == j) {
							if (seen1 == 1 && seen2 == 2) {
								works = 0;
							}
							seen1 = max(seen1, seen2) + 1;
						}
						if (lines[l][x] == k) {
							if (seen2 == 1 && seen1 == 2) {
								works = 0;
							}
							seen2 = max(seen1, seen2) + 1;
						}
					}
				}
			}
		}
		
		// check for intersection in adjacent lines
		for (int j = 0; j < n; j ++) {
			for (int k = j+1; k < n; k ++) {
				for (int l = 1; l < m; l ++) {
					vector <int> seen1 = {}, seen2 = {};
					vector <int> a = {}, b = {0, 0}, c = {1, 1}, d = {0, 0, 1, 1}, e = {0, 1, 1, 0}, f = {1, 0, 0, 1}, g = {1, 1, 0, 0};
					for (int x = 0; x < lines[l].size(); x ++) {
						if (lines[l][x] == j) {
							seen1.push_back(0);
						}
						if (lines[l][x] == k) {
							seen1.push_back(1);
						}
					}
					for (int x = 0; x < lines[l-1].size(); x ++) {
						if (lines[l-1][x] == j) {
							seen2.push_back(0);
						}
						if (lines[l-1][x] == k) {
							seen2.push_back(1);
						}
					}
					if ((seen1 != seen2) && seen1 != a && seen2 != a) {
						if ((seen1 == e && seen2 != b)
						|| (seen2 == e && seen1 != b)
						|| (seen1 == f && seen2 != c)
						|| (seen2 == f && seen1 != c)
						|| (seen1 == g && seen2 == d)
						|| (seen2 == g && seen1 == d)) {
							works = 0;
						}
					}
					
				}
			}
		}
		
		if (works) {
			cout << "YES\n";
		}
		else {
			cout << "NO\n";
		}
		
	}
	
	
	return 0;
}

