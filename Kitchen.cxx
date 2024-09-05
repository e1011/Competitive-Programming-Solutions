#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n, m, k, totalhours = 0;
	cin >> n >> m >> k;
	
	vector <int> arr1(n, 0), arr2(m, 0);
	for (int i = 0; i < n; i ++) {
		cin >> arr1[i];
		totalhours += arr1[i];
		if (arr1[i] < k) {
			cout << "Impossible\n";
			return 0;
		}
	}
	for (int i = 0; i < m; i ++) {
		cin >> arr2[i];
	}
	
	vector <vector <int>> dp1(90001, vector <int> (2, -1));
	vector <vector <int>> dp2(90001, vector <int> (2, -1));
	dp1[0] = {0, 0};
	for (int i = 0; i < m; i ++) {
		for (int j = 0; j < 90001; j ++) {
			if (dp1[j][0] != -1) {
				vector <int> newsum = dp1[j];
				newsum[1] += min(arr2[i], n);
				if (newsum[1] >= n) {
					newsum[1] -= n;
					newsum[0] += 1;
				}
				dp2[j+arr2[i]] = max(dp2[j+arr2[i]], newsum);
				dp2[j] = max(dp2[j], dp1[j]);
			}
		}
		dp1 = dp2;
	}
	
	for (int i = totalhours; i < 90001; i ++) {
		if (dp1[i][0] >= k) {
			cout << i - totalhours << "\n";
			return 0;
		}
	}
	cout << "Impossible\n";
	
	
	return 0;
}


