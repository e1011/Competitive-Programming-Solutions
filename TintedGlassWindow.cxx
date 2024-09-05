#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long n, t, ans=0;
	cin >> n >> t;
	
	vector <vector <long long>> prefixsum(2*n, vector <long long> (2*n, 0)), horizontal(0), vertical(0), rectangles(0);
	for (int i = 0; i < n; i ++) {
		long long x1, y1, x2, y2, t;
		cin >> x1 >> y1 >> x2 >> y2 >> t;
		horizontal.push_back({x1, i, 1});
		horizontal.push_back({x2, i, 0});
		vertical.push_back({y1, i, 1});
		vertical.push_back({y2, i, 0});
		rectangles.push_back({x1, y1, x2, y2, t});
	}
	
	sort(horizontal.begin(), horizontal.end());
	sort(vertical.begin(), vertical.end());
	for (int i = 0; i < 2*n; i ++) {
		if (horizontal[i][2] == 1) {
			rectangles[horizontal[i][1]][0] = i;
		}
		else {
			rectangles[horizontal[i][1]][2] = i;
		}
		if (vertical[i][2] == 1) {
			rectangles[vertical[i][1]][1] = i;
		}
		else {
			rectangles[vertical[i][1]][3] = i;
		}
	}
	
	/*
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < 5; j ++) {
			cout << rectangles[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	
	for (int i = 0; i < n; i ++) {
		prefixsum[rectangles[i][0]][rectangles[i][1]] += rectangles[i][4];
		prefixsum[rectangles[i][2]][rectangles[i][1]] -= rectangles[i][4];
		prefixsum[rectangles[i][0]][rectangles[i][3]] -= rectangles[i][4];
		prefixsum[rectangles[i][2]][rectangles[i][3]] += rectangles[i][4];
	}
	/*
	for (int i = 0; i < 2*n; i ++) {
		for (int j = 0; j < 2*n; j ++) {
			cout << prefixsum[i][j] << " ";
		}
		cout << "\n";
	}
	*/
	
	for (int i = 0; i < 2*n; i ++) {
		for (int j = 0; j < 2*n; j ++) {
			if (i > 0 && j > 0) {
				prefixsum[i][j] -= prefixsum[i-1][j-1];
			}
			if (i > 0) {
				prefixsum[i][j] += prefixsum[i-1][j];
			}
			if (j > 0) {
				prefixsum[i][j] += prefixsum[i][j-1];
			}
			if (prefixsum[i][j] >= t) {
				ans += (horizontal[i+1][0]-horizontal[i][0])*(vertical[j+1][0]-vertical[j][0]);
			}
		}
	}
	
	cout << ans << "\n";
	
	return 0;
}

