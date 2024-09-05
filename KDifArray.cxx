#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	vector <long long> arr(n, 0);
	vector <vector <long long>> dp((1 << n), vector <long long> (n, 0));
	for (int i = 0; i < n; i ++) {
		cin >> arr[i];
		dp[(1 << i)][i] = 1;
	}
	
	for (int i = 0; i < (1 << n); i ++) {
		for (int j = 0; j < n; j ++) {
			for (int l = 0; l < n; l ++) {
				if (((1 << l) & i) == 0) {
					if (abs(arr[l]-arr[j]) > k) {
						dp[i | (1 << l)][l] += dp[i][j];
					}
				}
			}
		}
	}
	
	long long ans = 0;
	for (int i = 0; i < n; i ++) {
		ans += dp[(1 << n) - 1][i];
	}
	cout << ans << "\n";
	
	return 0;
}

