#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int n, sq;
bool comp(vector <int> a, vector <int> b) {
	if (a[0]/sq != b[0]/sq) {
		/*
		if (a[0]/sq % 2 == 0) {
			return a[1] < b[1];
		}
		else {
			return a[1] > b[1];
		}
		* */
	}
	return a[0]/sq < b[0]/sq;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	sq = sqrt(n);
	
	vector <vector <int>> points(0);
	for (int i = 0; i < n; i ++) {
		int x, y;
		cin >> x >> y;
		points.push_back({x, y, i});
	}
	
	sort(points.begin(), points.end(), comp);
	for (int i = 0; i < n; i ++) {
		cout << points[i][2]+1 << " ";
	}
	cout << "\n";
	
	return 0;
}


// sort by x coordinate into blocks of sqrt(10^6)
// 10^3*10^6 for transitions
// 10^3*10^6 for processing y values of batches
// 10^3*10^6 for x values
// merge transitions and y values by starting at bottom every other batch
