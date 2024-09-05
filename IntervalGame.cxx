#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <vector <int>> intervals;

int grundy(int l, int r) {
	vector <int> MEX(101, 0);
	for (int i = 0; i < intervals.size(); i ++) {
		if (intervals[i][0] >= l && intervals[i][1]-1 <= r) {
			MEX[grundy(l, intervals[i][0]-1)^grundy(intervals[i][1], r)] = 1;
		}
	}
	for (int i = 0; i < 101; i ++) {
		if (MEX[i] == 0) {
			return i;
		}
	}
}

int main() {
	int t;
	cin >> t;
	
	for (int i = 0; i < t; i ++) {
		int n;
		cin >> n;
		
		intervals = vector <vector <int>> (n, vector <int> (2, 0));
		for (int j = 0; j < n; j ++) {
			cin >> intervals[j][0] >> intervals[j][1];
		}
		
		if (grundy(0, 100) == 0) {
			cout << "Bob\n";
		}
		else {
			cout << "Alice\n";
		}
	}
	
	
	return 0;
}

